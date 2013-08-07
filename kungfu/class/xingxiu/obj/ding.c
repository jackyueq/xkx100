// ding.c ��ľ����

inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(YEL"��ľ����"NOR, ({ "shenmu wangding", "ding" }));
	set_weight(500);
	set("count", 200);
	set_max_encumbrance(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
YEL"����һ��ɫ����Ƶ�ССľ����ľ���������Ǿ�ϸ��ľ�ʼ�����
����ľ��֮������ԼԼ�ķ���"RED"��˿"YEL"�����������ͭǮ���Բ�ף�
ľ���뾱����һ��ϸ�죬�ƺ���Ϊ���ء�\n    �����������õ�(use)��\n"NOR);
		set("value", 2000);
	}
}

int is_container() { return 1; }

void init()
{
	add_action("do_use","use");
}

int do_use(string arg)
{
	object env, target, ob = this_object(), me = this_player();
	string targetname, bugname, bugunit;
	mapping fam;
	int hgdf_sk, poison_sk, skpoint;
	
	if (!present(ob,me)) return 0;

	if( !arg || sscanf(arg, "%s with %s", arg, targetname)!=2 )
		return notify_fail("�÷��� use ding with ������������\n");

	if ( !id(arg) )
		return notify_fail("��Ҫ��ʲô��");

//	if( query("count") < 1)
//		return notify_fail("���ľ���������ò��������²������ˡ�\n");

	env = environment(me);
	hgdf_sk = me->query_skill("huagong-dafa", 1);
	poison_sk = me->query_skill("poison", 1);

	if( env->query("no_fight") )
		return notify_fail("���ﲻ�ʺ�������ľ����������\n");

	if( !objectp(target = present(targetname, env)) )
		return notify_fail("�㸽��û������ˡ�\n");

	if( target == me)
		return notify_fail("�Լ����Լ���ҩ�ޣ�̫��ֵ�˰ɡ�\n");

	if( target->query("race") != "����" ) 
		return notify_fail("���������ı������ˡ�\n");

	if( living(target) && !target->query_temp("noliving") ) 
		return notify_fail("��ֻ���Ҹ���ʡ���µ������������ҩ�ޡ�\n");

	if (!(fam = me->query("family")) || fam["family_name"] != "������")
		return notify_fail("����ͼ�뿴����ľ����ɶ�ã����ǿ�������\n");

	if( hgdf_sk < 20)
		return notify_fail("�㻯���󷨻�򲻹�������ʹ����ľ������\n");

	if( poison_sk < 20)
		return notify_fail("��Ļ�������̫�ͣ�û���ֵ�ľ���Ķ�����\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ����ľ������\n");

	if( me->is_fighting() )
		return notify_fail("ս�����޷�����ʹ����ľ������\n");

	if( me->is_busy() )
		return notify_fail("����æ���أ����п�����ˮĥ����\n");

//	add("count", -1);
	skpoint = poison_sk + random(hgdf_sk);

	switch( random(5))
	{
		case 0:
			bugunit = HIR"һ�������޵�";
			bugname = HIR"�����"HIG;
			break;
		case 1:
			bugunit = HIC"һֻ���ɫ��";
			bugname = HIC"��֩��"HIG;
			break;
		case 2:
			bugunit = BLK"һֻ���ߺڸ�";
			bugname = BLK"��Ы��"HIG;
			break;
		default:
			bugunit = HIW"һ���������";
			bugname = HIW"������"HIG;
	}

	message_vision(HIG"
$Nȡ��һֻ���ɫ��Сľ�����������ڵ��£��ִӶ���ȡ��һ��СС
���������˿����������Ǽ����ɫ����ɫ����ɫ�����ϡ�$N��ÿһ��
���������������붦�У��û𵶡���ʯ�����˻�����������Ȼ���
�϶��ǡ�

����һ�󣬺����òݴ���ɪɪ���죬�̲���"+bugunit+bugname+"��ֱ��
��ľ�����Ӷ��µĿ������˽�ȥ���㲻�ٳ�����

$N��$n�������ľ����"+bugname+"һ���죬��һ��ҧס��$n����ָ��
���˺�һ�ᣬ����$n����ָ������������һ������֮ɫ����ɫ��ǳ��
�����ת����ڣ��ٹ�һ�ᣬ��ɫ��ָ���ƣ����������ֱ�������

����Ƭ�̣�ľ���Ŀ�����һ�εκ�Ѫ����������$N����ϲɫ��æ����
��ѪҺ��ס����ϥ�˹�����ѪҺ���������ڡ����˺�һ�ᣬľ�����޺�
ɫ���£�$N˫��һ�꣬���Լ�����ʱ��������ֻ�����������覣���
�ް��Ѫ�ۡ�\n"NOR, me, target);

	target->receive_wound("qi", 40); 
	if (hgdf_sk > 20 && hgdf_sk < 150)
	{
		if( SKILL_D("huagong-dafa")->valid_learn(me) )
		{
			me->improve_skill("huagong-dafa", random(skpoint));
			tell_object(me, HIC"��ġ������󷨡������ˡ�\n"NOR);
		}
	}
	if (poison_sk > 20 && poison_sk < 100)
	{
		if( SKILL_D("poison")->valid_learn(me) )
		{
			me->improve_skill("poison", random(skpoint));
			tell_object(me, HIC"��ġ����������������ˡ�\n"NOR);
		}
	}
	me->start_busy(3);
	return 1;
}


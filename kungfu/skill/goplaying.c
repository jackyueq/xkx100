// goplaying.c ������̸
// Last Modified by winder on Jun. 10 2000

#include <ansi.h>;
inherit SKILL;

void init();
int do_play(string arg);

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	int lvl;

	lvl = (int)me->query_skill("goplaying", 1);

	if ( me->query("int") < 24 && me->query_int() < 32)
	return notify_fail("�����黭���Ǽ������֮�£�" +RANK_D->query_respect(me)+"�ƺ�̫����������Щ��\n");

	if( (int)me->query("shen") < -10000 )
	return notify_fail("��ɱ�����飬����������ƽϢ����ͷħ������ֻ�����˼�������壿\n");

	if (lvl > 29 && me->query("kar") != 29 &&
		me->query("family/master_name") != "�����" )
		return notify_fail("�������ʣ���ֻ����ϰ����̶��ˡ�\n");
	else return 1;
}

int practice_skill(object me)
{
	return notify_fail("������̸ֻ�ܿ�ѧϰ����ߡ�\n");
}
void init()
{
	add_action("do_play", "play");
}

int do_play(string arg)
{
	object me = this_player();

	if ( present("wei qi", this_player()) && ((arg == "wei qi") ||
		(arg == "qi") || (arg == "go")) )
	{
		if ( (me->query_skill("art", 1) < 40) )
		{
			message_vision("$N�ڳ�һ�����̣����о�Χ�壬ȴ�ܾ����ķ����ң�������������\n", me);
			me->receive_damage("jing", random(20) );
			me->receive_damage("qi", random(20) );
			return 1;
		}
		if ( me->query_skill("art", 1) >100 )
		{
			message_vision("$N�ڳ�һ�����̣�ֻ�����沼�־��ڳ��ֻ֮�У����ܿ��С�\n", me);
			return 1;
		}

		me->receive_damage("jing", 10);
		me->receive_damage("qi", 10);
		me->improve_skill("art", (int)me->query_int()/4 + (int)me->query_skill("art", 1)/10);
		tell_object(me, "��ڳ�һ�����̣��о���Χ������ֻ������ƽ���ͣ��ܿ�ͷ·��붨�ˡ�\n");

		message_vision("ֻ��" + me->query("name") +
		"���˴󷢣��������������������·��Ų��ʣ�һ��Ī������ģ����\n",
		environment(me), ({me}) );

	}
	return 1;
}

int help(object me)
{
	write(HIC"\n������̸��"NOR"\n");
	write(@HELP

    ��ң����ʦ��ң��ѧ�����ˣ�������ѧ������������������
�ž��գ��������� (luteplaying)��������̸ (goplaying)����ī
����(painting)������֮��(medicine)����ľ����(construction)��
԰��ݪ��(horticulture)����԰����(dramaturgy)��

	ѧϰҪ��
		�ޡ����츳���������˶Ը�������Ŭ��
HELP
	);
	return 1;
}


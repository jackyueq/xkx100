// chui.c 
#include <weapon.h>;
#include <ansi.h>;
inherit HAMMER;

void create()
{
	set_name(HIC"�׹���"NOR, ({"leigong hong", "hong", "chui" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "iron");
		set("long", HIC"�׹���Ϊһ���˽�С���������������ߣ���ͷ��û���˵�ȭͷ��\n�������ʱ������(zhi)�С�\n"NOR);
		set("wield_msg", HIC"$N�����������������䣬�漴�������������������һ���˽�С����\n"NOR);
		set("unwield_msg",HIC"$N������С��������һ���Ͳ����ˡ�\n"NOR);
	}
	init_hammer(5);
	setup();
}

void init()
{
	add_action("do_zhi","zhi");
}

int do_zhi(string arg)
{
	object *inv, obj, weapon, me = this_player();
	int attacklvl, dodgelvl, parrylvl, equip;
	string msg;
	object piece;
	
	if (environment(this_object())!=me)
		return 0;
	if(environment(me)->query("no_fight"))
		return notify_fail("�����ֹս����\n");
	if( (me->is_busy() ))
		return notify_fail("��������æ���أ�û���������׹��䡹��\n");
	if( !(me->is_fighting() ))
		return notify_fail("���׹��䡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( !arg )
		return notify_fail("��Ҫ����˭��\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("����û������ˣ�\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	if( !me->is_fighting(obj) )
		return notify_fail("���׹��䡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( obj == me ) return notify_fail("���Լ������벻������\n");
//	obj = me->select_opponent(); 

	attacklvl = me->query_skill("chengzi18po", 1);
	parrylvl = obj->query_skill("parry", 1);
	dodgelvl = obj->query_skill("dodge", 1);
	if( me->query("neili", 1) < 500 )
		return notify_fail("����������㣬���������׹��䣡\n");
	if( me->query_skill("qingming-xuangong", 1) < 30 )
		return notify_fail("�����ڤ������򲻵����޷������׹��䣡\n");
	if( attacklvl < 10 )
		return notify_fail("��ĳ���ʮ���ƻ�򲻵����޷����׹��䣡\n");

	me->add("neili", -200);
	msg = HIY"$N��ָһ�񣬰˽��׹������ַɳ���\n"NOR;

//	if( random(attacklvl) > (int)((parrylvl+dodgelvl)/2))
		if( attacklvl*3/4 > random(parrylvl+dodgelvl))
	{
		inv = all_inventory(obj);
		msg += HIY"$nֻ����ǰһ�ɾ������������䡱��һ����"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
				msg += HIY"һЩϡϡ���������µ����˵��ϣ�\n"NOR;
        seteuid(getuid());
        piece = new("/clone/misc/piece");
        piece->set("name",inv[equip]->query("name") + "����Ƭ");
        piece->set("long", "һ���������£������ǲ�Ƭ��Ƭʲô�ġ�\n");
        piece->move(environment(obj));
        destruct(inv[equip]);
			}
		}
	}
	else
	{
		msg += HIG "ֻ��$n���Ų�æһ��������˷������׹��䣡\n"NOR;
		if(userp(me)) me->add("neili",-400);
		me->start_busy(4);
	}
	message_vision(msg, me, obj);

	if(userp(obj)) obj->fight_ob(me);
	else if( !obj->is_killing(me) ) obj->kill_ob(me);
//	destruct(this_object());
	this_object()->move(environment(me));
	return 1;
}


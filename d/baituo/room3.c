// Room: /d/baituo/room3.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
int do_da(string arg);
void create()
{
	set("short","������");
	set("long", @LONG
�����ǰ���ɽ���ӵ������ҡ���������ҿ���һ�ˣ�ֻ�м������
��ľ׮(zhuang)�������ӵ��С�
LONG	);
	set("exits",([
		"out" : __DIR__"liangong",
	]));
	set("item_desc", ([
		"zhuang":"һ��ľ׮������ľ�˵����ӹ̶��ڵ��ϣ����˻���(da)������\n",
	]));     
	set_temp("full",0);
	set("no_clean_up", 0);
	set("coor/x", -49990);
	set("coor/y", 20030);
	set("coor/z", 30);
	setup();
}

void init()
{
	object ob=this_player();
	if((int)query_temp("full")==2)
	{
		message_vision("$Nһ���������Ѿ������ˣ�ֻ�����˳�ȥ��\n",ob);
		ob->move(__DIR__"liangong");
		return;
	}
	add_temp("full" ,1);
	add_action("do_da", "da");
	return;
}

int valid_leave(object who, string dir)
{
	add_temp("full",-1);
	return 1;
}
int do_da(string arg)
{
	object me = this_player();
	int jing1, qi1, exp, lvl;
	object weapon;

	exp = me->query("combat_exp");
	lvl = me->query_skill("staff",1);
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר��������\n");
	if (!living(me)) return notify_fail("�㷢���ˣ�\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("�������������ȷ��ġ�\n");
	if (!arg || arg!="zhuang") return notify_fail("��Ҫ��ʲô��������\n");
	jing1 = random((int)me->query("con"))+1;
	qi1 = random((int)me->query("str"))+1;
	if ((int)me->query("jing") < jing1 || (int)me->query("qi") < qi1)
	{
		message_vision("$N��һ�ɣ�һ��С���Դ�ײ����ľ׮�ϣ�\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", jing1);
	me->receive_damage("qi", qi1);       
	message_vision("$Nվ������������ȣ���ʼ��ľ׮�Դ�������\n", me);
	if ( lvl < 30 && lvl*lvl*lvl/10 < exp && random(10) > 4 )
	{
		me->improve_skill("staff", (int)(me->query("int") / 5));
	}
/*
	if ( (int)me->query("combat_exp") < 30000) 
	{
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("int") / 10)));
	}
*/
	return 1;
}


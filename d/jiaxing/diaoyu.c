// Room: /d/jiaxing/diaoyu.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����һ��ʯ���ľ���Сͤ����ĿԶ������ˮ���죬�������١�����
������੣�����һȦȦ������
LONG
	);
	set("outdoors", "jiaxing");
	set("no_fight",1);
	set("no_steal",1);
	set("no_sleep",1);
	set("no_beg",1);
	set("fish",200);
	set_temp("char_count",2);

	set("exits", ([
		"south" :  __DIR__"nanhu",
	]));
	set("coor/x", 1510);
	set("coor/y", -990);
	set("coor/z", 0);
	setup();
}

void init()

{
	add_action("do_diao","diao");
	add_action("do_ban","dazuo");
	add_action("do_ban","tuna");
	add_action("do_ban","du");
	add_action("do_ban","study");
	add_action("do_ban","exercise");
	add_action("do_shuohua","say");
	add_action("do_shuohua","whisper");
	add_action("do_shuohua","reply");
	add_action("do_shuohua","tell");

}
int do_shuohua()
{
	write ("��˵��������������ˣ�\n");
	return 1;
}
int do_ban()
{
	write ("������˼ҵ��㣡\n");
	return 1;
}
int do_diao(string arg)
{
	object me = this_player();
	int bonus,exp,pot;
	object mon;

//	if((int)(me->query("combat_exp")) > 15000)
//	      return notify_fail("��ľ���̫���ˣ����ﲻ�ʺ��㡣\n");
	if (query_temp("char_count") < 1)
	      return notify_fail("����̫ӵ���ˡ�û���¹�����ͷ�����ɡ�\n");
	if (query("fish") < 1)
	      return notify_fail("���������ò���ˣ����쿴������Ӱ����ͷ�����ɡ�\n");
	if (!arg)
	      return notify_fail("��Ҫ��ʲô��\n");
	if (arg != "fish" && arg != "��")
	      return notify_fail("��ɲ��ǽ�̫����ûָ��������ġ�\n");
	if( (int)me->query_temp("fishing") ) 
	      return notify_fail("���Ѿ��ڵ����ˡ�\n");
	if ((int)(me->query("qi")) < 16)	
	      return notify_fail("���Ѿ�̫���ˣ�������Ϣһ�°ɡ�\n");
	message_vision("
$N��������ڹ��ϣ�����һ����ͣ�������ӽ�ˮ�\n\n",me);
	me->set_temp("fishing",1);
	add_temp("char_count", -1);
	add("fish", -1);
	me->add("qi",-10);

	call_out("del_fishing", 6, me, mon, bonus, exp, pot);
	return 1;
}

void del_fishing(object me, object mon, int bonus, int exp, int pot)
{
	me->delete_temp("fishing");
	add_temp("char_count", 1);
	if (random (10) < 2)
	{
		message_vision(HIY"
ֻ����Ư΢΢һ����$N�Ͻ�������ͣ�������һ�����װ׵��㹳��ʲôҲ
û�С�����̫�ļ��ˣ�û������Թ�����������ˡ�\n"NOR,me);
		me->start_busy(3);
		return ;
	}
	else
	{
		exp = 2 + random(6);
		pot = 1 + random(3);
		message_vision(HIW"
��Ư�ڶ��ˣ�$N��Ϣ������������ס��Ư��������˿�����⣬ֻ����Ư��
������һ����$Nץסʱ��һ��ͣ�$N������һ��" + chinese_number(exp) + "���ص��㡣\n\n"NOR 
"$N����ͻȻ���һ���㷷��һ�ѽ�$N���е�����ߣ�˳���Ӹ�$Nһ�����ӡ�\n",me);
//	bonus = (int) me->query("combat_exp");
//	bonus += exp;
//	me->set("combat_exp", bonus);
//	bonus = (int) me->query("potential");
//	bonus += exp;
//	me->set("potential", bonus);
		mon = new("/clone/money/silver");
		mon->set_amount(exp);
		mon->move(me);
		me->start_busy(3);

		return;
	}
}
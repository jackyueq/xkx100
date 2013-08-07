// Room: /d/baituo/shulin1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void init();
int cut(string);

void create()
{
	set("short","����");
	set("long", @LONG
������һƬï�ܵ�����(wood)�������Է��������������˲�н��ɽ
�������������С·�Ա�����һ��ľ��(pai)��
LONG);
	set("exits",([
		"east" : __DIR__"shulin",
		"southwest" : __DIR__"caomeidi",
	]));
	set("outdoors", "baituo");
	set_temp("times" , 5);
	set("no_clean_up", 0);
	set("item_desc", ([
		"pai" : "��������  ��������\n",
		"wood" :"һƬ�ɿ��������֡�\n",
	]) );
	set("coor/x", -50040);
	set("coor/y", 20020);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_cut","cut");
}

int do_cut(string arg)
{
	object me=this_player();
	object ob;
	if (!arg||arg!="wood") return notify_fail("��Ҫ��ʲô��\n");
	if (present("chai dao",me)) return notify_fail("û�в���ô����\n");
	if (query_temp("times")==0) return notify_fail("������������\n");
	if(me->query("qi")<20) return notify_fail("�����̫���������ܿ���\n");
	ob=new(__DIR__"obj/chai");
	ob->move(environment(me));
	me->receive_damage("qi", 20);
	add_temp("times",-1);
	message_vision("$N����һ�����۵ù�Ǻ��\n" , me);
	return 1;
}

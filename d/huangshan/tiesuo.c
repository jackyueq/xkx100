// Room: /d/huangshan/tiesuo.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG

�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�

LONG
	);
	set("exits", ([ 
		"west" : __DIR__"xuanyuan",
		"east" : __DIR__"huangshan",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
}
void init()
{
	object ob, me = this_player();

	if(me->query_kar() < random(30))
	{
		me->move(this_object());
		message_vision("$N����һ�����ȣ���������ֱˤ��ȥ��\n", me);
		ob = load_object(__DIR__"kuzhu");
		me->move(ob);
		message_vision("ֻ����һ���ҽУ�$N��֪��ʲô�ط����ص�ˤ��������\n", me);
		me->unconcious();
	}
	return;
}

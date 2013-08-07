// Room: /d/baituo/yuanzi3.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "Ժ��");
	set("long", @LONG
����ѷ����ϰٶѵ�ʯͷ����Щʯͷ�д���С������һ�䷿�ݣ�С��
һ��Ѽ������״��඼�ʳ����Ρ��㷢�ִ���Щʯͷ֮��ķ�϶(fengxi)
��Ʈ��һ�ɹɵ��ȳ�ζ��ʹ���Ҫ��Ż�ˡ�
LONG);
	set("exits", ([
		"west"      : __DIR__"yuanzi4",
		"southwest" : __DIR__"yuanzi2",
		"northwest" : __DIR__"yuanzi5",
	]));
	set("item_desc", ([
		"fengxi": "\n��϶�������һƬ������ԼԼ��ɳɳ�����졣\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49900);
	set("coor/y", 20080);
	set("coor/z", 30);
	set("outdoors", "baituo");
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_skill("poison", 1) < 50)
	me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if (arg == "fengxi" )
	{
		message_vision("$N�ٿ���϶�ڵ���ʯ�ӡ�\n", me); 
		message("vision", me->name() + "һ��������϶�����˽�ȥ��\n", environment(me), ({me}) );
		me->move(__DIR__"fengxi1");
		message("vision", me->name() + "���������˽�����\n", environment(me), ({me}) );
		return 1;
	}
}
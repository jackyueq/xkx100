// Room: /d/xingxiu/xiaolu.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ�������޺�������ʯ������᫵�С·�ϣ�·����һȺ����
�������ڳ�Х����������������������������ƺư��﷽Բ�����޺���
������������֮����ɽ�ڣ�������һ͹���ľ�ʯ(jushi) ��
LONG);
	set("exits", ([
		"west"    : __DIR__"xxh1",
		"northup" : __DIR__"shanbi",
	]));
	set("item_desc", ([
		"jushi" : "һ���׸ߵĺں�ɫ��ʯ��\n"
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/tianlang"  : 1,
		__DIR__"npc/xxdizi" : 1,
	]));
	set("coor/x", -49900);
	set("coor/y", 20200);
	set("coor/z", 0);
	set("outdoors", "xingxiu");
	setup();
}

void init()
{
	add_action("do_pa", "pa");
	add_action("do_pa", "climb");
}

int do_pa(string arg)
{
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");

	if( !arg || arg=="" ) return 0;
	if( arg=="jushi" )
	{
		if ((!myfam || myfam["family_name"] != "������") &&
			(present("tianlang zi", environment(me)))) 
			return notify_fail("������������������ǰ, �ȵ����������ľͿ������\n");
		if(me->query_skill("dodge") < 100)
			return notify_fail("�������Ͼ�ʯ�������������ϲ�ȥ��\n");       
		message_vision("$N�ܷѾ������Ͼ�ʯ��\n", me);
		message("vision", me->name() + "һת�۱���ʧ��ɽ���ϡ�\n", environment(me), ({me}) );
		if ( time()-me->query_temp("LAST_PKER_TIME")<7200)
		{
			write( WHT"�����Ͼ�ʯ��ȴ����������������֮����ֻ���㬵�����������\n"NOR );
			me->move( __DIR__"xiaolu" );
			return 1;
		}
		me->move(__DIR__"jushi");
		message("vision", me->name() + "��ɽ��������������\n", environment(me), ({me}) );
		return 1;
	}
}

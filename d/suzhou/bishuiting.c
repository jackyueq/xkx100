// Room: /d/suzhou/bishuiting.c
// Last Modified by winder on Mar. 8 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_press();
int valid_leave();

void create()
{
	set("short","��ˮͤ");
	set("short", HIC"��ˮͤ"NOR);
	set("long", @LONG
���Ǻ��е�һ��Сͤ�ӣ�������ȥ�����Կ�����������ľ�ɫ����
���Ŀ�������ͤ�ӱ��Ͽ̻��Ž���ˮ������˷羰�������������롣ͤ
����һ����(liang)��
LONG );
	set("exits",([
		"south" : __DIR__"huzhongdao",
	]));
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("item_desc", ([
		"liang" : "�������Ϻõ��ľ���ģ����滹��ʮ�ֹŹֵ��ֻ���\n",
	]));
	set("coor/x", 800);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
	me = this_player();
	if (arg !="liang") return notify_fail("��Ҫ����ȥ��\n");
	if (me->query_dex()<20) 
		write("����ͼ���Ϸ������������������ݣ�ֻ�����ա�\n");
	else
	{
		write("������Ծ���˷�����\n");
		message("vision", me->name() + "һ����Ծ���˷�����\n", environment(me), ({me}) );
		me->move(__DIR__"liang");
		message("vision", me->name() + "������Ծ��������\n", environment(me), ({me}) );
		return 1;
	}
}


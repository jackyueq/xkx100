// Room: /d/nanshaolin/xctang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIR"������"NOR);
	set("long", @LONG
һ���������ң���������ľ���ɣ�������ɽ�������ı����𣬶�
��ʯ�ڡ����ɽ��ʯ�ң����ǻ�Ȼ��ɣ�������ǰ����ɮ���������ǻۣ�
���������ɽ�����ˡ��������ͨ�������겻Ϣ�����й������ҷ�ķ�
�����ͬ������ǧ�����������ơ�ְ��ɮ�ڵ����Ĵ�Ѳ�ӣ���
�����衣һλ��ɮ�Ŀ���������Ӳ�����
LONG );
	set("exits", ([
		"west"  : __DIR__"xclang",
		"south" : __DIR__"xcping",
		"north" : __DIR__"duanya",
	]));
        set("objects",([
		CLASS_D("nanshaolin")+"/dabing" : 1,
        ]));
        set("coor/x", 1820);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

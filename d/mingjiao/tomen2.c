// Room: /d/mingjiao/tomen2.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��ʯ��");
    set("long", @LONG
���ֽ�����������ǰ������һ������ʯ�������ֱͨ��ǰ������
��ϡϡ��������ż��ð�����ȴ�Եøߴ�ͦ�Σ��������֦������ո�
����չ�š��ɴ�����ԶԶ��ȥ����һ����ש���ߵĻֺ��լ��
LONG );
    set("exits", ([
		"west"  : __DIR__"tomen1",
		"east"  : __DIR__"shanjiao",
		"south" : __DIR__"mjsimen",
    ]));
    set("objects", ([
		__DIR__"npc/gaoshanwang": 1,
    ]));
    set("no_clean_up", 0);
    set("outdoors", "mingjiao");
	set("coor/x", -51000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}
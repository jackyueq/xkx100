// Room: /d/mingjiao/tomen1.c
// Date: Java 97/05/11

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "��ʯ��");
    set("long", @LONG
ʯ���������ƺ���ÿ�����Щ�����µ�ɽ��������������˾����
Ϊһˬ��Զ����������ˮ�������н�Զ��ɽ���Ϲ����˺��ܵ����ܣ���
������ҡ߮��
LONG );
    set("exits", ([
		"west" : __DIR__"shanmen",
		"east" : __DIR__"tomen2",
    ]));
    set("outdoors", "mingjiao");
    set("no_clean_up", 0);
	set("coor/x", -52000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}
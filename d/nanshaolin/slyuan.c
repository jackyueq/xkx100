// Room: /d/nanshaolin/slyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", HIY"����Ժ"NOR);
	set("long", @LONG
����һ���ž���СԺ��Ժ�ж��������õ�ľ�񣬼������ײ�ɮ��
��ɮ����������æµ�š�����������ɮ��Բ�ź󣬷ٻ������ĳ�����Ժ
���������һ��С�š�
LONG );
        set("no_fight",1);
	set("outdoors","nanshaolin");
	set("exits", ([
		"east" : __DIR__ "huaishu4",
		"west" : __DIR__ "talin1",
        ]));
        create_door("west", "ľ��", "east", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


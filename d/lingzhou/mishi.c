// d/lingzhou/mishi.c

#include "room.h"

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƷ�õ����ң�ƽʱֻ������һ���˿��Խ��������Ҳ���ȴ��
����������������ɺ���½�����ë��֯��̺���ĸ����������ţ�;�
��һ�ſ��������������룬��ɫ��ɴ�����ڴ����Ϸ������ߵİ�
���ϰ��ŵ��½������������ѿ���ȥ��Ө��͸����ǽ���Ŵ���ʯ�Ƶ���
�ӣ�һ����������ϵ���ͭ��¯��Ʈ�˹�����
LONG
	);
	set("exits", ([
		"east" : __DIR__"yipindating",
	]));
	create_door("east","ľ��","west",DOOR_CLOSED);
	set("objects", ([
		__DIR__"npc/duan" : 1,
	]));
	set("coor/x", -17980);
	set("coor/y", 32100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

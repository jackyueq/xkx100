// shiji4.c
// Modified by Winder June.25 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��б�����ϵ�ʯ���������һ�������ɡ�ȱ����������ת��
�����䣬����������¡��¡��ˮ����
LONG );
	set("exits", ([
		"southdown" : __DIR__"fangjian3",
		"eastup"    : __DIR__"shiji5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21010);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}
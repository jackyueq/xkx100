// Room: /d/nanshaolin/fotaout.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ŷ�������");
	set("long", @LONG
��������ͨ���γɵ���ɫ�������㣬�˽����ܣ��Թ��ƴ�ש���졣
�����Ի���ʯ������������ש������������ɣ�������������һ������
�ߵĹ���С�š�
LONG );
	set("exits", ([
		"south" : __DIR__"talin11", 
		"enter" : __DIR__"fota1",       
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


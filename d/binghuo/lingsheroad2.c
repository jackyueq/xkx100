// Room: /binghuo/lingsheroad2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�����������е�С·�ϣ�����Ƨ��������е���Ϣ����쳣����
�ܲ�������������գ�������������һ�����������������ߵ���
��ôû���������أ�
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"lingsheroad1",
		"eastup"    : __DIR__"lingsheroad3",
	]));
	set("objects", ([
		__DIR__"npc/liuyun"   : 1,
		__DIR__"npc/miaofeng" : 1,
		__DIR__"npc/huiyue"   : 1,
	]));
	setup();
	replace_program(ROOM);
}


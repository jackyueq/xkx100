// Room: /binghuo/lingsheroad1.c
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
		"west"    : __DIR__"lingshedao",
		"northup" : __DIR__"lingsheroad2",
	]));
	setup();
	replace_program(ROOM);
}


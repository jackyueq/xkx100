// Room: /binghuo/lingsheroad4.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�����������е�С·�ϣ�����Ƨ��������е���Ϣ����쳣����
�ܲ�������������գ�������������һ�������ɽ������С�ݵ���
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"  : __DIR__"lingshegang",
		"westup"    : __DIR__"lingshetop",
	]));
	setup();
	replace_program(ROOM);
}


// Room: /d/suzhou/.c
// Last Modified by winder on Mar. 8 2001

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
���������ŵ���լ��ס��֪���ļҾ졣���˵��˾͸�ֹ���ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"yamen",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -995);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


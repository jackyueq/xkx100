// Last Modified by Sir on 9/17/2001
// wg_lang3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�һֱͨ���Ժ���ϱ��������䳡��
LONG);
	set("exits", ([
		"east" : __DIR__"wg_shilu-4",
		"west" : __DIR__"wg_wuchang3",
	]));
	set("outdoors", "wuguan");
	set("coor/x", 31);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


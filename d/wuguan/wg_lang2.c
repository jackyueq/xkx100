// wg_lang2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�ͨ�����䳡�����������ģ��������֡�
LONG);
	set("exits", ([
		"south" : __DIR__"wg_wuchang2",
		"north" : __DIR__"wg_dayuan",
	]));
	set("objects", ([
		__DIR__"npc/wg_xiaohs" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 11);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


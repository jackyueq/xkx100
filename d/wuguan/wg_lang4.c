// wg_lang4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�����������ڵ���Ʒ����Ҫ����������µ��˶���ȥ
��Ʒ���칤�ߣ������������䳡��
LONG);
	set("exits", ([
		"east" : __DIR__"wg_wupinfang",
		"west" : __DIR__"wg_wuchang4",
	]));
	set("objects", ([
		__DIR__"npc/wg_thddizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 31);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


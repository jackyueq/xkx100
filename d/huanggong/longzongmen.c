// Room: /d/huanggong/longzongmen.c

inherit ROOM;

void create()
{
	set("short", "¡����");
	set("long", @LONG
������ͨ��������·�Ĵ���. ����·��̫��ľ���. ¡���������
��������.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 6 */
		 "northeast" : __DIR__"qianqingmen",
		 "southeast" : __DIR__"baohedian",
		 "south"     : __DIR__"yongxiang1",
		 "west"      : __DIR__"ciningmen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/quanzhou/huajiaoting.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����һ�����ڴ�·�����Сͤ�ӣ����������������ڴ���Ϣ����ȥ
����˳���ţ���ͨ���ۿڡ�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"shunjiqiao",
		"north" : __DIR__"jishi",
	]));
	set("coor/x", 1850);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

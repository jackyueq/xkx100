// Room: /d/songshan/huayuan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ��С԰�ӣ��������������ͨ���ͥ��԰�����Ų����滨��
�ܣ�ɽʯ��׾�����ǻ��˲��Ƶľ����Ͳ�����������ʯС·������ݵ�
�ʹ��׹�ľ�н�����ɽ�紵��������һ�ػ��ꡣ
LONG );
	set("exits", ([
		"north" : __DIR__"houting",
		"south" : __DIR__"chitang",
		"east"  : __DIR__"eastpath3",
		"west"  : __DIR__"westpath3",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 920);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

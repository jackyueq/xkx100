// Room: /d/quanzhou/road2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����Ȫ�ݵ�һ���ɵ����������ŷ��ľ����������Ϣ����ȥ�ɴ�
���⽻ͨʹ�ڸ����������������¥��
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east"   : __DIR__"yanyu",
		"north"  : __DIR__"road1",
		"south"  : __DIR__"shibosi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1860);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

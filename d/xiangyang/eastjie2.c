// Room: /d/xiangyang/eastjie2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����Ǻܴ��ʮ�ֽֿڣ������Ƕ��ڴ�֣�������һ����
������˵��Ǯ��һ�㶼ס�����棬����ͨ�������ǵ������ţ�
�����ɵ�������㳡��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"eastjie3",
		"west"  : __DIR__"eastjie1",
		"south" : __DIR__"jiedao",
		"north" : __DIR__"eastroad1",
	]));
	set("coor/x", -480);
	set("coor/y", -510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
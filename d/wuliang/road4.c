// Room: /wuliang/road4.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����ǽ������������������ɽ��������չ����ͨ������
������������������˵ľ����������ˡ�
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"  : __DIR__"jianhugong",
		"south"    : __DIR__"zhengting",
	]));
	set("coor/x", -71000);
	set("coor/y", -79880);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
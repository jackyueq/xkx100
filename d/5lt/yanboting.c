// Room: /d/5lt/yanboting.c

inherit ROOM;

void create()
{
	set("short", "�ݲ���");
	set("long", @LONG
�����ǵ���̨�Ķ๦���ݲ��������������񡢵ƹ⡢���֡��α���
һ����æ�ò��ɿ�����
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"down"      : __DIR__"mishuchu",
		"east"      : __DIR__"sheyingpeng",
		"northeast" : __DIR__"houtai",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

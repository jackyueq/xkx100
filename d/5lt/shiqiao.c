// Room: /d/5lt/shiqiao.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ֻ��һ��Сʯ�ţ���Ȼ����ȴ�ǳ������������ϵ������໨��
�������������
LONG
	);
	set("exits", ([
		"north"   : __DIR__"nroad2",
		"south"   : __DIR__"nroad1",

	]));
	set("outdoors", "5lt");
	set("no_clean_up", 0);

	set("coor/x", -150);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

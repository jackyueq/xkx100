// Room: /d/5lt/yuelanshi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǵ�֧���������ҡ��Դ��������Ƚ��Ķ�ý���豸������ͳ�
��������ϯ��
LONG );
	set("exits", ([
		"south" : __DIR__"chuandashi",
	]));
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
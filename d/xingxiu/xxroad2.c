// Room: /d/xingxiu/xxroad2.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ����ʯ�����������Լ���Կ������ݳǵĳ�ǽ����������С
ɽ��
LONG );
	set("exits", ([
	    "east"    : __DIR__"xxroad1",
	    "northup" : __DIR__"xxroad3",
	    "westup"  : "/d/qilian/bonanshan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "silu");
	set("coor/x", -9600);
	set("coor/y", 2700);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

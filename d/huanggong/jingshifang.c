//jingshifang.c

inherit ROOM;

void create()
{
	set("short", "���·�");
	set("long", @LONG
���ǹ��ڵļ�촦, �ǹ���̫��Ĺ������, ̫���ܹܶ��ڴ˵�.
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"qianqinggong",
	]));
	set("objects", ([
		__DIR__"npc/hai": 1,
		__DIR__"npc/xiaoguizi": 1,
	]));
	set("coor/x", -210);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
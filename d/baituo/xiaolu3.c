// Room: /d/baituo/xiaolu3.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ����ɽ��С·��С·�����Ӳݴ����������������ˡ�����
·��ȴ����ƽ����������������һ�㡣��˵��������ɽ����û��Ҫ��
��С�ġ�
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"northeast" : __DIR__"xiaolu4",
		"southdown" : __DIR__"xiaolu2",
	]));
	set("objects",([
		__DIR__"npc/shanzei1" : 1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20010);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

// Room: /d/baituo/xiaolu2.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ����ɽ��С·��С·�����Ӳݴ����������������ˡ�����
·��ȴ����ƽ����������������һ�㡣�㲻���е���ԥ��
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"northup"   : __DIR__"xiaolu3",
		"southdown" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

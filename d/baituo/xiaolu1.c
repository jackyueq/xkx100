// Room: /d/baituo/xiaolu1.c
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
		"northup"   : __DIR__"xiaolu2",
		"southwest" : __DIR__"dongjie",
		"northeast" : __DIR__"fendi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49970);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

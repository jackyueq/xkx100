//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "С��");
	set ("long", @LONG
���Ǿ��ݳ��ڵ�С������Ǹ߸ߵ�Χǽ��Ƨ�����ˣ�����������
��������������һ��С�֣�����������������·����
LONG);

	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"dongjie1",
		"west"  : __DIR__"xiang2",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1480);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
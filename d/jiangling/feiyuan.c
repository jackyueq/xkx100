//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��԰");
	set ("long", @LONG
һ�������Ļ�԰���¹��¼�����԰���������֮�У�����һ��СС
���ϻ���ӭ��ҡҷ�����й¼�����֮�⡣�Ĳ��У���һ�갼��͹͹����
����÷�ں����а�����
LONG);

	set("exits", ([ 
		"north" : __DIR__"lingtang",
		"east"  : __DIR__"loudi",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2039);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

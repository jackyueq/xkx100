//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��");
	set ("long", @LONG
������ҶѷŲ�ݵĵط���
LONG);
	set("exits", ([
		"west"  : __DIR__"nanlou",
	]));
	set("objects", ([
		__DIR__"npc/wukan"    : 1,
	]));
  
	set("coor/x", -1488);
	set("coor/y", -2041);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

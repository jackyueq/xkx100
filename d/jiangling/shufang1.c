//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "�鷿");
	set ("long", @LONG
��������ү�ӵ��鷿����������ࡣ����һ�°�ǽ�ر����ۡ�
LONG);
	set("exits", ([
		"west" : __DIR__"beilou",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1488);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
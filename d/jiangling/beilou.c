//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��¥");
	set ("long", @LONG
��������ү��ס�ĵط�����������࣬����һ��ľ������ש����
�м�����͹��������������ϰ�����¡�
LONG);
	set("exits", ([
		"south" : __DIR__"dating",
		"east"  : __DIR__"shufang1",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1489);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

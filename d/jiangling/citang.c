//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG
����һ���ưܵ����á��������ǻҳ������ζ������ǲ��ơ�
LONG);
	set("exits", ([
		"north" : __DIR__"huayuan",
	]));
	set("objects", ([
		__DIR__"npc/taohong" : 1,
	]));
  
	set("coor/x", -1486);
	set("coor/y", -2041);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

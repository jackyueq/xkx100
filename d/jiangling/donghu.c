//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
һ����̵ĺ�ˮ��������죬�����̲���ã��һ�ɽ��Ϻ÷羰��
LONG);
	set("exits", ([
		"west" : __DIR__"huanghelou",
	]));
  
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1390);
	set("coor/y", -2220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{
	set ("short", "��");
	set ("long", @LONG
һ��������ʪ���������߾�ͷ��һ���η�����֪������������Ѻ
��͢�ط��ĵط���
LONG);
	set("exits", ([ 
		"east" : __DIR__"laofang",
		"west" : __DIR__"lingtang",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1460);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

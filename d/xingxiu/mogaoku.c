// /d/xingxiu/mogaoku.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "Ī�߿�");
	set("long", @LONG
����ǽ���ϻ�����������صĻ��棬����Ů���죬���з������á�
���л��кܶ����;��顣�㱻��Щ�������Ļ�֮�������ˡ�
LONG );
	set("exits", ([ 
	     "out" : __DIR__"yueerquan",
	]));
	set("objects", ([ 
		"/d/shaolin/obj/fojing1"+random(2) : random(2),
		"/d/shaolin/obj/fojing2"+random(2) : random(2),
	]));
	set("coor/x", -20310);
	set("coor/y", 170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}


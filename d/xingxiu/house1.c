// /d/xingxiu/house1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "�����ҿ���");
	set("long", @LONG
���ǰ����ҵĿ������������Ų�˹��̺��ľ���ϰ�����ԭ�Ĵ�����
���ó���ҵ�����һ������Ǯ��
LONG );
	set("exits", ([ 
	    "west" : __DIR__"house",
	]));
	set("objects", ([
		__DIR__"npc/afanti": 1
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xiyu");

	set("coor/x", -38800);
	set("coor/y", 13000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

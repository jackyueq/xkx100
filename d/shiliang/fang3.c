// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "�෿");
	set("long", @LONG
��������¼������·�ʩ��ס������˵����ʯ���ڱ���̫�ã�
��Ҫ�Ǻ�ɫ���㿴������������һ��Ѿ���ڵ��顣
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"zoulang5",
	]));
	set("objects", ([
		__DIR__"npc/wenfangshi" : 1,
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", 1630);
	set("coor/y", -1940);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// hsroad3.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
һ���ӿ����ݵ���·������������ͨ��ɽ�
LONG );
        set("outdoors", "village");
	set("exits", ([
		"southeast" : __DIR__"hsroad2",
		"north"     : __DIR__"sexit",
	]));
	set("objects", ([
		"/d/taishan/npc/tangzi" : 4,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -970);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
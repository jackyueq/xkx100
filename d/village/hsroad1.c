// hsroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��ϱ�ͨ�����ݳǡ�
LONG );
        set("outdoors", "village");

	set("exits", ([
		"north" : __DIR__"hsroad2",
		"south" : "/d/changan/road2",
	]));
	set("objects", ([
		__DIR__"npc/girl" : 4,
	]));

//	set("no_clean_up", 0);
	set("coor/x", -960);
	set("coor/y", 190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ����������Ĵ���������������У�ʮ�����֡����߾��ǳ�
���š�
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"wangfu2",
		"east" : __DIR__"chaoyang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -170);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

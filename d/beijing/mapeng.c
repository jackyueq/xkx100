inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǿ���������������к�����������һ���ţ�����ͳ��㡰
�ֻ֡�ֱ�С�
LONG );
	set("exits", ([
		"west" : __DIR__"kang3",
	]));
	set("objects", ([
		__DIR__"npc/yucongma" : 1,
	]));
	set("coor/x", -179);
	set("coor/y", 4082);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

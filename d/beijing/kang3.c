inherit ROOM;


void create()
{
	set("short", "������Ժ");
	set("long", @LONG
�����ǿ�����Ժ��������һ��С��԰��������һ�������ߵ�ֱͨ��
���á�������һ������ϱ߾��ǿ������ȥ��˽�����䳡��
LONG
);
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"mapeng",
		"north" : __DIR__"neitang",
		"south" : __DIR__"kang2",
	]));
	set("objects", ([
		__DIR__"npc/guanjia" : 1,
		"/d/city/npc/jiading" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4082);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

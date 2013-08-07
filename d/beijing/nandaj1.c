// Room: /beijing/nandajie1.c

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ϴ�֡��������찲�Ź㳡���ϱ����ϴ�ֹ㳡��������һ
�ҵ��̣�ǽ��д��һ�����ġ������֣���ϸ��������������ѹ�͵���
�ۻ��۵�������������һ��С�͵ꡣ
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"dangpu",
		"south" : __DIR__"nandaj2",
		"east" : __DIR__"kedian",
		"north" : __DIR__"tian_anm",
	]));
        set("objects", ([
		"/d/shaolin/npc/tiao-fu" : 1,
		__DIR__"npc/xiaofan" : 1,
        ]));
	set("coor/x", -200);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

//guangchang.c

inherit ROOM;

void create()
{
	set("short", "��㳡");
	set("long", @LONG
�����㳡�ĵ����̵�ʯש��������, ��һʮ���. �ǻʵ�Ϊ����
���ڵص��빬�ص���Ƶ�. ����ʳǵĽ䱸ɭ��֮��.
LONG
	);
	set("outdoors", "huanggong");
        set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"wenhua",
		"west"  : __DIR__"wuying",
		"south" : __DIR__"taihemen",
		"north" : __DIR__"taiji",
	]));
	set("objects", ([
		__DIR__"npc/eshuo" :1,
	]));
	set("coor/x", -200);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
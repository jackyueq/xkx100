inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
��������������֡�������һ�Һܴ�Ķĳ��������ֺ��ġ�����
�����ı���֡��ϱ߾��������ˡ�
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"north" : __DIR__"xisi",
		"south" : __DIR__"xidan",
		"east"  : __DIR__"duchang",
		"west"  : __DIR__"hai_men",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

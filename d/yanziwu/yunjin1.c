// Room: /d/yanziwu/yunjin1.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "�ƽ�һ¥");
	set("long", @LONG
С¥����һ���Ҷд�š��ƽ�¥������ī��׭�֣�¥��ǰ������
�ֵĶ��ǲ軨������Щ�軨�ڴ�����������������ɫ�����⾫�µ�¥
��ͤ���ȣ�δ�ⲻ�ġ�
LONG );
	set("exits", ([
		"north"  : __DIR__"path8",
		"south"  : __DIR__"garden",
		"up"     : __DIR__"yunjin2",
	]));
	set("objects", ([
		"/d/dali/obj/chahua11" :1,
		__DIR__"npc/xiaocha" :1,
	]));
	set("coor/x", 1230);
	set("coor/y", -1260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
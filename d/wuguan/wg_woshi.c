// wg_woshi.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
��������ݹ��������ң����Ӳ����󣬺�������ӣ����ӵ�������
���룬���ӹ��������������߰���һ���辰��һ��С�������ż����顣
LONG);
	set("exits", ([
		"west" : __DIR__"wg_lang5",
	]));
	set("objects", ([
		__DIR__"npc/wg_furen" : 1,
	]));
	set("coor/x", 41);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

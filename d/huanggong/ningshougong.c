// Room: /d/huanggong/ningshougong.c

inherit ROOM;

void create()
{
	set("short", "���ٹ�");
	set("long", @LONG
������̫�ϻ�������ĵط�������ȴ�ǹ����޹���ֻ��ǽ���ϡ�
�����ϣ����ǵ���Ƥ��֮��ı����������Ǹ����˵ľ��ң��������ǽ�
֦��Ҷ�Ĺ������ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		 "north" : __DIR__"changyinge",
		 "south" : __DIR__"huangjidian",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/jianning" : 1,
	]));

	set("coor/x", -180);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
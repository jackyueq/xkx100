// yuqinggong.c

inherit ROOM;

void create()
{
	set("short", "ع�칬");
	set("long", @LONG
����ǻ�̫�Ӷ���ĵط�. ̫������, �����ù�, ���ǻ��Ͼ�����
һЩ������׶�����̫��.
LONG
	);
	set("exits", ([
		"north"   : __DIR__"fengxianmen",
		"east"    : __DIR__"huangjimen",
		"west"    : __DIR__"rijing",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
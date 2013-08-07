// Room: /d/jiaxing/nanhu.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "�����Ϻ�");
	set("long", @LONG
�����Ǽ����Ϻ����ڽ������Ҷ���У����ⱥʵ��һ��������ת
�ĸ�����Ʈ����ˮ���ɵĺ����ϡ�������һ��������һ��������������
�á�
LONG );
	set("exits", ([
		"west"      : __DIR__"jiaxing",
		"east"      : __DIR__"jiaxinggang",
		"south"     : __DIR__"tieqiang",
		"north"     : __DIR__"diaoyu",
		"southeast" : __DIR__"nanhu1",
	]));
	set("outdoors", "jiaxing");
	set("objects", ([
		CLASS_D("gumu")+"/limochou" : 1,
		"/clone/medicine/vegetable/baizhi" : random(2),
	]));
	set("coor/x", 1510);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

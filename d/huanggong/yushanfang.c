// yushanang.c
inherit ROOM;

void create()
{
	set("short", "���ŷ�");
	set("long", @LONG
ԶԶ�����ŵ�һ������ζ�����Ʈ��. ���������ŷ�. �����˵Ȳ�
���ڴ˳���. һ���ų����ϰ���������ζ, �޲����˴�������. ������
���ϳԵ�, ����Ҳ����.
LONG
	);

	set("exits", ([
		"north" : __DIR__"jianting",
		"south" : __DIR__"houyuan",
		"west"  : __DIR__"qinghedian",
	]));
	set("objects", ([
		__DIR__"npc/taijian":1,
		__DIR__"obj/yuchi" : 2,
	]));

	set("coor/x", -180);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/chengdu/xijie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���������ֵ����ƻ��ӣ����Ʈ������������αȵĵ��̣�����
һЩС̯С����·�������⣬ż���йٱ��жӾ���������һ��С���
����������Щ�¹ڳ����Ķ����ˣ��ϱ��и����̡����������ǳ��ǵ�·��
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xijie1",
		"west"  : __DIR__"westgate",
		"north" : __DIR__"xiaoxiang",
		"south" : __DIR__"dangpu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


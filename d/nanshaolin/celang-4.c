// Room: /d/nanshaolin/celang-4.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ԵĲ��ȡ�����������������Ҳ�ò�������˸��ַ�
���ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡�����Ʈ����
���׷������㣬����ɮ�������ŵ�ի�á�
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east"      : __DIR__"zhaitang",
		"south"     : __DIR__"celang-3",
                "northwest" : __DIR__"sblu-1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


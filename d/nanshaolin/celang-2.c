// Room: /d/nanshaolin/celang-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ԵĲ��ȡ�����������������Ҳ�ò�������˸��ַ�
���ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡����洫����
��ľ����û�����������󳪡�
LONG
	);
	set("outdoors", "nanshaolin");
	set("exits", ([
		"northeast" : __DIR__"sblu-1",
		"south"     : __DIR__"celang-1",
                "west"      : __DIR__"zdyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


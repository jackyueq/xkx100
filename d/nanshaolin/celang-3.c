// Room: /d/nanshaolin/celang-3.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ԵĲ��ȡ�����������������Ҳ�ò�������˸��ַ�
���ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡��ɴ���ͨ
����¥��������һƬ�㳡��
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east"  : __DIR__"zhonglou",
		"south" : __DIR__"gchang-3",
                "north" : __DIR__"celang-4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


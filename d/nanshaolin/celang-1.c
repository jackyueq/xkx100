// Room: /d/nanshaolin/celang-1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ԵĲ��ȡ�����������������Ҳ�ò�������˸��ַ�
���ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡��ɴ�����ͨ
���¥��������һƬ�㳡��
LONG
	);
	set("exits", ([
		"west"  : __DIR__"gulou",
		"south" : __DIR__"gchang-2",
                "north" : __DIR__"celang-2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


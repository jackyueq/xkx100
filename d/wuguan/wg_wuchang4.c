// wg_wuchang4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
����¶�����䳡���ö�����������������ţ������ڳ��У�û����
��ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ��򣬵��Ϸ��ż���������
�ߡ�
LONG);
	set("exits", ([
		"east" : __DIR__"wg_lang4",
		"west" : __DIR__"wg_wuchang2",
	]));
	set("objects", ([
		__DIR__"npc/wg_daotong" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 21);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
}


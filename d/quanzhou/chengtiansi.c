// Room: /d/quanzhou/chengtiansi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ȫ����������󰲵������Ա������������ȷ�ǣ������˳����
�ڹ㳡������һ��̳������������ͨ����ͩ��·��
LONG );
	set("exits", ([
		"west"      : __DIR__"southroad2",
		"northeast" : __DIR__"guitangxiang",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

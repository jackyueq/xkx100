// Room: /d/xingxiu/xxhb4.c
// Last Modified by Winder on Apr. 25 2001

inherit ROOM;
void create()
{
	set("short", "���߻�·");
	set("long", @LONG
һ����᫵�С·�������Ƿ�Բ�����һ���޼ʵ����޺���������
һƬɽʯ������������̣����������������ܲݼ䣬��ʱ�ж����û��
��е��е㷦����Ъ��һ��������ǰ�ߡ�
LONG);
	set("exits", ([
		"east"   : __DIR__"xxhb2",
		"westup" : __DIR__"shanshi",
	]));
	set("objects", ([
		__DIR__"npc/boshou"  : 1,
		__DIR__"npc/xxdizi" : 1,
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -50200);
	set("coor/y", 20400);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}


// Room: /d/quanzhou/mituoyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ľ���죬��ʯ����������ʱ�ڣ��з��������������ϴ�����
��������ǧ��ϸĭ��ʫ�ƣ�����ǧ�㴵���ϣ���������ӿ���ࡣ�ٱ���
���ʯ���ţ��ұ�С���������������ϸ��һ�ߣ���Ϊ��һ���졹֮��
�ڡ�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"liandanshi",
		"northwest" : __DIR__"qianshouyan",
	]));
	set("coor/x", 1830);
	set("coor/y", -6400);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

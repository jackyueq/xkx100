// Room: /d/quanzhou/northroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��������ˮ���������ַǷ�����������
�����������Ĺ㳡�����ӵ�����ԶԶ���������������мҺ踣¥��
LONG );
	set("outdoors", "quanzhou");
	set("objects", ([ 
		__DIR__"npc/youxun" : 1,
	]));
	set("exits", ([ 
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"north" : __DIR__"northroad2",
	]));
	set("coor/x", 1850);
	set("coor/y", -6520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

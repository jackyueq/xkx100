// Room: /d/quanzhou/southroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ�����ͩ��·
�Ķ����Ǵ����������һ��Ƭ��լ����ͨ�˴������ݺ�ϷԺ����
�߱������ֵ����Ĺ㳡��
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([ 
		"east"  : __DIR__"daxixiang",
		"west"  : __DIR__"zhaiqu1",
		"north" : __DIR__"guangchang",
		"south" : __DIR__"southroad2",
	]));
	set("coor/x", 1850);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

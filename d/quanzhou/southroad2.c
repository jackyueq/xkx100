// Room: /d/quanzhou/southroad2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ����ɴ˶���
�㵽�����£���������լ����������һ��������լ����Ȫ�ݳ�����Դ��
�ñ������ߡ�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([ 
		"east"      : __DIR__"chengtiansi",
		"west"      : __DIR__"zhaiqu3",
		"north"     : __DIR__"southroad1",
		"southeast" : __DIR__"alabo",
	]));
	set("coor/x", 1850);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/quanzhou/westroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ������߱���
�����Ŀ�Ԫ�¼����ŵ��š�������һ���ӻ��̡�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"westroad2",
		"east"  : __DIR__"guangchang",
		"north" : __DIR__"zahuopu",
	]));
	set("coor/x", 1840);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

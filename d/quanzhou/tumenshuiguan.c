// Room: /d/quanzhou/tumenshuiguan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "Ϳ��ˮ��");
	set("long", @LONG
����ȥ���ۿڵ���Ҫͨ�������СϪ֮�ϣ�ΡȻ��������ν������
�ɣ����һ��
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"tumenji",
		"east" : __DIR__"lingshan",
	]));
	set("coor/x", 1870);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

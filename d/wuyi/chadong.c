// Room: /d/wuyi/chadong.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�趴");
	set("long", @LONG
�趴�����񻪶������ɶ������񶴣���ʵ���Ƕ�����һƬ�������
��Ͽ�ȡ������ұڻ��ƣ�����������Ҫ��������ѩ��ʯ����ˮ���ľ���
御������ұ��ϡ��趴�����֣��پ���������ζ�������ǡ���ɽ��
��Ӣ�������ӣ�Ʒ���ҹǻ���֮ʤ���������Ҳ�����������ɸ���
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"westup"    : __DIR__"tianyoupath1",
		"southwest" : __DIR__"shaibuyan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -4980);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


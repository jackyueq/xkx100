// Room: /d/nanshaolin/xiaolu5.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��
ľ������΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ���
���������ڡ�
LONG );
	set("exits", ([
		"west" : __DIR__"xiaolu6",
		"east" : __DIR__"sblu-2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}


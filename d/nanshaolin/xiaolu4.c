// Room: /d/nanshaolin/xiaolu4.c
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
		"east"      : __DIR__"xiaoxi",
		"northwest" : __DIR__"xiaolu3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1860);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}


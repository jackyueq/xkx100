// Room: /d/nanshaolin/shanroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���������ֺ������һ��С·��·�Գ�������ݡ������̾͵�С·
���������������ƺ����˾�����ɨ����Զ�����Ǻ�ɽ��ɽ��ͦ�Σ�����
���ģ���������������������΢���������������������
LONG );
	set("exits", ([
		"north" : __DIR__"shanroad2",
		"south" : __DIR__"qfdian",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}


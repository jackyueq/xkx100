// Room: /d/nanshaolin/shanroad7.c
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
		"northeast" : __DIR__"shanroad8",
		"southdown" : __DIR__"shanroad6",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6020);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}


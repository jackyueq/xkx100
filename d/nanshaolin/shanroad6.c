// Room: /d/nanshaolin/shanroad6.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���������ֺ������һ��С·��·�Գ�������ݡ������̾͵�С·
���������������ƺ����˾�����ɨ����Զ�����Ǻ�ɽ��ɽ��ͦ�Σ�����
���ģ���������������������΢���������������������ǰ����������
��һƬ�ܴ�����֣�һ��С��ֱͨ���ڡ�
LONG );
	set("exits", ([
		"northup"   : __DIR__"shanroad7",
		"southdown" : __DIR__"shanroad5",
                "northwest" : __DIR__"bamboo1",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6030);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}


// Room: /d/nanshaolin/shanroad3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���������ֺ������һ��С·��·�Գ�������ݡ������̾͵�С·
���������������ƺ����˾�����ɨ��ǰ�����ֺ�ɽ��ɽ��ͦ�Σ����㾳
�ģ���������������������΢���������������������
LONG );
	set("exits", ([
		"north"     : __DIR__"shanroad4",
		"southdown" : __DIR__"shanroad2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}


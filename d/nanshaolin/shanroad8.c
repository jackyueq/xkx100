// Room: /d/nanshaolin/shanroad8.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���������ֺ������һ��С·��·�Գ�������ݡ������̾͵�С·
���������������ƺ����˾�����ɨ��ǰ����Ǻ�ɽ��ɽ��ͦ�Σ����㾳
�ģ���������������������΢���������������������������һƬ���֣�
��������һ��ľ��(mupai)��
LONG );
	set("exits", ([
		"east"      : __DIR__"shulin1",
		"southwest" : __DIR__"shanroad7",
        ]));
        set("item_desc",([
		"mupai"	:   "�����»������֣�Υ��������ɱ���⣡\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1830);
	set("coor/y", -6010);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}


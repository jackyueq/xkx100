// Room: /d/nanshaolin/xiaolu3.c
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
		"southeast" : __DIR__"xiaolu4",
		"southwest" : __DIR__"xiaolu2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6140);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}


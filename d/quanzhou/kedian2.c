// Room: /d/quanzhou/kedian2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�
����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ�
����Ǯ������˯����
LONG );
	set("exits", ([
		"down"  : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1860);
	set("coor/y", -6520);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

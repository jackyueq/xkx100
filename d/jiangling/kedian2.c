// Room: /city/kedian2.c

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
	set("coor/x", -1490);
	set("coor/y", -2130);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
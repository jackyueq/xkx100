// Room: /d/yueyang/kedian2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "ĵ��¥��¥");
	set("long", @LONG
��������ĵ��¥��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�
������һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ�
������Ǯ������˯����
LONG );
	set("exits", ([
		"down"  : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -2280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

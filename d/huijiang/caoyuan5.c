// Room: /d/huijiang/caoyuan5.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
��������˼������Ĵ��ԭ��һ���޼ʵĲݵ���粨������ؽ���
���м����ڵ㣬���ܷǳ��İ�����ֻ�ǲ�ʱ����Ů�����ĸ�����֪����
��Ʈ��Ĵ���.
LONG );
	set("outdoors", "huijiang");
	set("exits", ([
		"north" : __DIR__"caoyuan6",
		"south" : __DIR__"caoyuan4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50050);
	set("coor/y", 9110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

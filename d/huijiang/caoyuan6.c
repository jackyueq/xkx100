// Room: /d/huijiang/caoyun6.c
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
		"northwest" : __DIR__"xiagu",
		"south"     : __DIR__"caoyuan5",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/wei-chunhua" : 1,
	]));
	set("coor/x", -50050);
	set("coor/y", 9120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

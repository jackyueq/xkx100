// Room: /d/honghua/caoyuan4.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
��������˼������Ĵ��ԭ��һ���޼ʵĲݵ���粨������ؽ���
���м����ڵ㣬���ܷǳ��İ�����ֻ�ǲ�ʱ����Ů�����ĸ�����֪����
��Ʈ��Ĵ�����
LONG );
	set("exits", ([
		"north" : __DIR__"caoyuan5",
		"south" : __DIR__"caoyuan1",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/chang-hezhi" : 1,
		CLASS_D("honghua")+"/chang-bozhi" : 1,
	]));
	set("outdoors", "huijiang");
	set("coor/x", -50050);
	set("coor/y", 9100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


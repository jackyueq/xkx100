// Room: /d/chengdu/xiaoxiang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���������ű���һ�������С���֪��ͨ��������ﲻʱ����
���ؾ����߹�����Ҳ����������Ǵ��������
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"south"     : __DIR__"xijie",
		"northeast" : __DIR__"path1",
	]));

	set("coor/x", -8080);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


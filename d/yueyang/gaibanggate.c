// Room: /d/yueyang/gaibanggate.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ������ǰ�����ſڽ��������Ķ���һ����ؤ��磬������
ͻȻ����������ǽ����е�ؤ����ɡ��������ƾɾɵģ��þ������
�������ڿ��ѣ���������̦��ֻ������ͭ�Ż�ĥ��ý��������
LONG );
	set("outdoors", "yueyang");
	set("exits", ([
		"north" : __DIR__"gaibangyuan",
		"south" : __DIR__"xijie",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/xi" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 5,
	]));
	set("coor/x", -1420);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "ؤ��") && dir == "north" &&
		objectp(present("xi zhanglao", environment(me))))
		return notify_fail("�ɳ�����ס��˵���˴��˱�����أ���ֹ����\n");

	return ::valid_leave(me, dir);
}

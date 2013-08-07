// Room: /d/quanzhou/liangcang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ռ�ؿ��Ŀⷿ���ѷ��Ŷѻ���ɽ�ľ������굽��������
Ҳ������֮�á����ڲֹ����٣����������ͽ�Ŀ��ӡ�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"northeast" : __DIR__"micangxiang",
		"south"     : __DIR__"eastroad1",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1860);
	set("coor/y", -6520);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northeast" && objectp(present("wu jiang", environment(me))))
		return notify_fail("�佫��ȵ���������������˵Ȳ����ɴ˾�����\n");
	return ::valid_leave(me, dir);
}


// Room: /d/quanzhou/dudufu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ȫ�ݶ����ĸ�ۡ��Ȫ�ݶ����ƹ�Ȫ�ݵĺ�½��Ȩ������������
����򣬹�Ͻ������ǿ���Զ��ˮʦ����һ��һ��Ҫ�Ĺ�ְ��
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west"  : __DIR__"duduxiang",
		"south" : __DIR__"micangxiang",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1870);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && objectp(present("wu jiang", environment(me))))
		return notify_fail("�佫��ȵ���������������˵Ȳ����ɴ˾�����\n");
	return ::valid_leave(me, dir);
}


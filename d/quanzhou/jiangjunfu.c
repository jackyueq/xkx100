// Room: /d/quanzhou/jiangjunfu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʩ�Ž�����");
	set("long", @LONG
����һ�����ƻֺ�Ĵ�լԺ�������߶������ܶ�����������졣��
��������Ϸ�����һ����ң������ĸ���������ġ��������������
�������֮լ������ʩ�Ž�������̨��Ĺ�����
LONG );
	set("exits", ([
		"west"  : __DIR__"daxixiang",
		"north" : __DIR__"jiangjunfu1",
		"south" : __DIR__"guitangxiang",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1870);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && objectp(present("wu jiang", environment(me))))
		return notify_fail("�佫��ȵ���������������˵Ȼرܣ�\n");
	return ::valid_leave(me, dir);
}


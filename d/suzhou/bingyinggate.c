// Room: /d/suzhou/bingyinggate.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "��Ӫ����");
	set("long", @LONG
����վ�ڱ�Ӫ���ſڣ������һ�ż�ª��Ӫ�������Կ��������Ʒ�
�Ĺٱ����ڲ�������ʱ�ش����ź������ϰ����ǲ������ڴ˹ۿ��ģ���
��øϿ��߿���
LONG
	);
	set("outdoors","suzhou");
	set("exits", ([
		"south" : __DIR__"bingying",
		"north" : __DIR__"xidajie1",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 840);
	set("coor/y", -1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}


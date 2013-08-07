// Room: /d/baituo/cave.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","�Ҷ�");
	set("long", @LONG
�����Ǵ��Ҷ��������ڡ�����ɽ������ĵ��������¾������������
�γɵġ��ϱ��������֡��������߾ͽ����ˡ�
LONG	);
	set("exits",([
		"north"     : __DIR__"cave1",
		"southdown" : __DIR__"zhulin",
	]));
	set("objects",([
		__DIR__"npc/mangshe" : 1,
	]));
	set("outdoors","baituo");
	set("coor/x", -50040);
	set("coor/y", 20070);
	set("coor/z", 40);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir =="north" )
	{
		if (objectp(present("mang she", environment(me))))
			return notify_fail("���ߵ�ס���ȥ·��\n");
	}
	return ::valid_leave(me, dir);
}



// Room: /d/baituo/ximen.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long", @LONG
���Ǹ�����ɽׯ�����š������ε����ŷ������£����Ϲ���һ����
�� (pai)�����������Ӳݴ�����
LONG	);
	set("exits",([
		"west" : __DIR__"cao1",
		"east" : __DIR__"changlang",
	]));
	set("item_desc",([
		"pai" : "���������ж��߳�û�����С�\n" ,
	]));
	set("objects",([
		__DIR__"npc/menwei" : 1,
	]));
	set("outdoors", "baituo");
	set("coor/x", -50030);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if( (dir == "east") && ((int)me->query("shen")>300) &&
		objectp(present("men wei", environment(me))) )
		return notify_fail("��������һ�����㲻�ܽ�ȥ��\n");
	if( (dir == "west") &&((int)me->query("combat_exp") < 300) &&
		objectp(present("men wei", environment(me))) )
		return notify_fail("��������һ������ľ���̫�ͣ��ᱻ����ҧ���ģ����ǲ�Ҫ�Ҵ��ĺá�\n");
	return ::valid_leave(me, dir);
}


// Room: /d/baituo/mumen.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","Ĺ��");
	set("long", @LONG
���Ǹ�һ������Ĺ�ص�Ĺ�š�����ʯ�񻨵���������ʯ���·�棬
�޼�����ĳ���ľ���Ե�ׯ�����¡�Ĺ�ű�����һ�����ɫʯ��(bei)��
LONG	);
	set("exits",([
		"south"     : __DIR__"fendi",
//		"northeast" : __DIR__"gongzhu",
	]));
	set("item_desc",([
		"bei" : "   �������ء�  \n�ޡ������ơ��߽��룡\n",
	]));
	set("objects",([
		__DIR__"npc/shiwei" : 1,
	]));
	set("outdoors", "baituo");
	set("coor/x", -49960);
	set("coor/y", 20010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "northeast") && (!present("jinpai",me)) &&
		objectp(present("shi wei", environment(me))) )
		return notify_fail("��������һ������û�С������ơ������ܽ�ȥ��\n");
	return ::valid_leave(me, dir);
}


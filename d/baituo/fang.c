// Room: /d/baituo/fang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
�����ǰ���ɽ���ӵ��������������м������䣬�������ҡ�������
������������գ����Բ��������˴����
LONG	);
	set("exits",([
		"west" : __DIR__"liangong",
		"1" : __DIR__"room1",
		"2" : __DIR__"room2",
		"3" : __DIR__"room3",
	]));
	set("objects",([
		__DIR__"npc/trainer" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
}
int valid_leave(object who ,string dir)
{
	if((string)who->query("family/family_name")!="����ɽ��" &&
		(dir!="west"))
		return notify_fail("�����ֹ���˽��룡\n");
	return 1 ;
}

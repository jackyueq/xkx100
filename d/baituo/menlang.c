// Room: /d/baituo/menlang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
���Ǹ����ȣ����ȵķ����Ϲ���һ������Сͭ�壬������з�����
�ද����������
LONG	);
	set("exits",([
		"north" : __DIR__"tangwu",
		"south" : __DIR__"liangong",
	]));
	set("objects",([
		__DIR__"npc/guanjia" : 1,
	]));
	set("outdoors","baituo");
	set("coor/x", -50010);
	set("coor/y", 20050);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}


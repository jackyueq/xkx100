//room: /d/baituo/liangong.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","������");
	set("long", @LONG
�����ǰ���ɽ���ӵ���������������һ���������������Ǹ����ȣ�
��������һ�����ȣ������������ǳ����ɡ�����ɼ�ΡΡ������
LONG	);
	set("exits",([
		"east" : __DIR__"fang",
		"north" : __DIR__"menlang",
		"west" : __DIR__"changlang",
		"south" : __DIR__"dating",
	]));
	set("objects",([
		CLASS_D("baituo")+"/li" : 1,
	]));
	set("outdoors", "baituo");
	set("coor/x", -50010);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}


// Room: /d/lingxiao/wuqi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����������ǵĵ����̡��߽�����������壬��������滹Ҫ�䡣
��ϸһ����ǽ�Ϲ����˴��СС������ɫɫ�ĵ�����һ��������������
ȫ����Ʒ��������ԯ���������˽������������ڵ�ӭ��ǰ����
LONG );
	set("exits", ([
		"east" : __DIR__"iceroad2",
	]));
	set("objects", ([
		__DIR__"npc/xuanyuan": 1,
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);
	set("coor/x", -31010);
	set("coor/y", -8910);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


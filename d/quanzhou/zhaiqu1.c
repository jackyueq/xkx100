// Room: /d/quanzhou/zhaiqu1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "լ��");
	set("long", @LONG
����Ȫ�ݾ�����������С���ݺᣬ��ͨ�˴һʽ��ʯ�����ݣ���
����ǽ�������Գƣ�����������ɫ����ν�������У�С�����硣������
��ϷԺ���ϱ�Ҳ��һ��Ƭլ����
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"southroad1",
		"west"  : __DIR__"xiyuan",
		"south" : __DIR__"zhaiqu2",
	]));
	set("objects", ([
		"/d/village/npc/boy" : random(3),
	]));
	set("coor/x", 1840);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

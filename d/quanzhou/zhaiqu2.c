// Room: /d/quanzhou/zhaiqu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "լ��");
	set("long", @LONG
����Ȫ�ݾ�����������С���ݺᣬ��ͨ�˴һʽ��ʯ�����ݣ���
����ǽ�������Գƣ�����������ɫ����ν�������У�С�����硣���ߺ�
�ϱ߶���լ������������Ȫ�����ġ�������ݡ������Ͽ�ͨ��Դ���á�
��ϷԺ���ϱ�Ҳ��һ��Ƭլ����
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"xiyuan",
		"southwest" : __DIR__"yuanhetang",
		"west"      : __DIR__"wuguangate",
		"south"     : __DIR__"zhaiqu3",
		"north"     : __DIR__"zhaiqu1",
	]));
	set("objects", ([
		"/d/village/npc/kid" : random(3),
		"/d/village/npc/oldwoman" : random(3),
	]));
	set("coor/x", 1840);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

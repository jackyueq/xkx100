// Room: /d/quanzhou/zhaiqu3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "լ��");
	set("long", @LONG
����Ȫ�ݾ�����������С���ݺᣬ��ͨ�˴һʽ��ʯ�����ݣ���
����ǽ�������Գƣ�����������ɫ����ν�������У�С�����硣���ߵ�
��ͩ��·�������ֵ��������������мҳ������۽������̡�Դ���á���
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"southroad2",
		"west"  : __DIR__"yuanhetang",
		"north" : __DIR__"zhaiqu2",
	]));
	set("objects", ([
		"/d/village/npc/girl" : random(3),
	]));
	set("coor/x", 1840);
	set("coor/y", -6560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

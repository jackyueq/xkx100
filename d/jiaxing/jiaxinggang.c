// Room: /d/jiaxing/jiaxinggang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "���˺���");
	set("long", @LONG
�����Ǽ��˺��ۣ����ڰ׷���㣬��ͷ��ͣ�źö��洬����Ҫ����
������æµ������������һ�����ϴ�������������ƴ���������ڴ�����
�﹤����Һ��ӡ������ǲ��٣�����һ�����һ���ȴ����ҡͷ��
LONG );
	set("exits", ([
		"west" : __DIR__"nanhu",
	]));
	set("objects", ([
		"/d/taohua/npc/laoda": 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiaxing");
	set("coor/x", 1520);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
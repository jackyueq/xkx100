// Room: /d/shaolin/shijie2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ʯ��������Ȼ��������ͷ����ߵ�ɽ�����ų������
�Ľ��󣬳����˱�������̦��������ϡ��Щ����ĺۼ�����һ��
���ر�����������շ�аħ��������Ⱥ����
LONG );
	set("exits", ([
		"southdown" : __DIR__"shijie1",
		"northup" : __DIR__"shijie3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	set("coor/x", -10);
	set("coor/y", 710);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
// Room: /d/shaolin/cjlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�ؾ�¥");
	set("long", @LONG
�����²ؾ�֮�������º�����ƥ�����ﶼ���������飬�߼������
��ܣ���ܼ��������һ��ͨ�еĿ�϶�����Ŵ�����м䣬����ط���
���ɳ���������
LONG );
	set("exits", ([
		"south" : __DIR__"daxiongbaodian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
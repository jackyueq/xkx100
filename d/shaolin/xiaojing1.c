// Room: /d/shaolin/xiaojing1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����������ɽ֮����һ��ɽ��ɽ���ϳ������޺�ɫ�Ĳ�֪����
Ұ�����ܵķ���Ǵس�һ����æµ�š���ʱ�м�ֻ�����С�ܷ��
�����ƺ������������֮�͸е�����ľ��档
LONG );
	set("exits", ([
		"east" : __DIR__"shijie1",
		"northup" : __DIR__"xiaojing2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	set("coor/x", -20);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
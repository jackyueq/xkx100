// Room: /city/huapeng.c

inherit ROOM;

void create()
{
	set("short", "��ҩ��");
	set("long", @LONG
������ҩ���������£�����ǰ�������ҩ�������ΰ��ֻ��������
����ǧ�٣��������룬ɷ�ǹ���������Ӱ������б���չ����ڻ�������
ǧ����ҩ֮�ϣ�譲ӻ���������֯��һ�㡣����һ����ҩ�����Ķ�󻨣�
������죬���н��ߣ����������Ľ��Χ�ˡ�
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"chanzhimenqian",
		"west"  : __DIR__"huadian",
	]));
	set("coor/x", -30);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/wuxi/road2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ݺ�����֮��Ĵ������������������������������֮
����ʹ�ò�����������̷�����������������֮��Ҳ�������鷳����
·�ϵ���Ҳ���ر�öࡣ
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"road3",
		"west"  : __DIR__"road1",
	]));
	set("coor/x", 600);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
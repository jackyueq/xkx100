// Room: /d/heimuya/road5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
������һ������·�ϡ������Ѿ������������ˣ���������һ������
����������������Ļ������£�û��һ˿���ĵ���ɫ����������������
ˮ�����졣
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
		"northeast" : __DIR__"weifen",
		"south"     : __DIR__"road6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1010);
	set("coor/y", 690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
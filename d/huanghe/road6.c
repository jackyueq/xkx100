// Room: /d/heimuya/road6.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
������һ������·�ϡ������ĵ��棬���ǿ������Ļ��������Ϸ���
ȥ��ԶԶ�и�ɽ���ƣ����������и�СС���䡣��������Ȯ�ͼ��䣬��
�㳤;�ı�������һ˿������
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
		"southeast" : "/d/village/wexit",
		"north"     : __DIR__"road5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1010);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /city/tianjing.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
�쾮��С������ʮ�ಽ�������������ǰ�ж��ң�����������õ�
Ժ����ͨ�����ŵı��࣬������ʮ���������ɴ˵�ɽ���ڶ��ڵ����࣬
��ʯ��������������ˮ�����С���쾮������˾��£����˵��˶���˼
����һ�ᣬ���δ�԰�Ĺ��������������־��⡣
LONG );
	set("exits", ([
		"northup" : __DIR__"shixingting",
		"north"   : __DIR__"hushishandong",
		"east"    : __DIR__"yamenyuan",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 1);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
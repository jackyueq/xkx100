// Room: /city/shixingting.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "ʫ��ͤ");
	set("long", @LONG
ͤ��֮������ȫ԰����ߵ㡣ͤ��Χ�԰�ʯ���������Թ���������
����ɽ���������ʯ��ᾣ������ɰش�����䣬���������������ǰ��
Զ����լ���۴Σ�������ˮƽ�羵��������������ʡ�������ʫ��ͤ��
LONG );
	set("exits", ([
		"northdown"  : __DIR__"luqiao",
		"southdown"  : __DIR__"tianjing",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 2);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
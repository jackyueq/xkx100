// Room: /city/hushishandong.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "��ʯɽ��");
	set("long", @LONG
���ں�ʯɽ���и�����Ѩ���࣬һ�������ͨ��⣬һ����Կ���
��ҡ��Ӱ������ɽ��������һ˿��Ϣ֮�С������ٳ�������ˮ��̡���
ɫƷ�ֵĽ��㣬Ⱥ���ڳصס�ˮ�ϼ�ʯ��������
LONG );
	set("exits", ([
		"north"  : __DIR__"luqiao",
		"south"  : __DIR__"tianjing",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 2);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
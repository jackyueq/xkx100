// Room: /d/wuxi/road16.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��������˿�ʼ��ɽ�����ܿ�ȥȺɽ���ƣ�����ȴ����һЩ�Ͱ�
��������ꡣɽ�ϸ����ŵĶ���������һ�Ĵ��֣�������ȥ��������
�̣�ԶԶ��ϡ����������Х��
LONG );
	set("outdoors", "yixing");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"  : __DIR__"road17",
		"east"     : __DIR__"road14",
	]));
	set("coor/x", 250);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

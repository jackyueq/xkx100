// Room: /d/wuxi/road15.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·�������ۣ����ܻ��ݳɴԣ�����ïʢ������Х��������ɽ
�����������ɽ�����µڶ�Ȫ����û��һƬ���ܵ�����֮�У���
��ɽ�ϾͿ�Ҫ����ɽ�Ķ����ˡ�
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"    : __DIR__"huishan",
		"southdown"  : __DIR__"huishanquan",
	]));
	set("coor/x", 260);
	set("coor/y", -170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
// Room: /heizhao/hetang.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "����");
	set("long", @LONG
��ɽ���������ĺ���������ϣ�������и�ïȻ�������װ׵�
�ɻ������ߵ̰������˲������������ɽ������չҡ���ţ�������
�졣��������Լ�����������������һ��Сʯ��ͨ�����档
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"shiliang3",
		"north"  : __DIR__"shiqiao",
	]));
	set("coor/x", -5020);
	set("coor/y", -1220);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
// Room: /d/jueqinggu/meiyupu.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "÷����");
	set("long", @LONG
����ٲ���Σ���ͱڶ�������ֱ�£����ٿڲ�Զ��һ��ͻ��ʯ����
ʯ�ɽ�������ëëϸ�꣬�����塢����÷�꣬����÷���١�
LONG
	);
	set("exits", ([
		"west" : __DIR__"guanlanting", 
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -470);
	set("coor/y", -380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


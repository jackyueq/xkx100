// Room: /d/nanshaolin/jnlwang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "����������");
	set("long", @LONG
������й����Ž��������������������ܵ�ǽ���ϻ���������ʤ
������ʮ��Ը����ʮ������ıڻ�����ͼ��ΰ��ɫ��Ѥ��������������
������ϸ�������м���������ڶ���Ĥ�ݡ�
LONG );

	set("exits", ([
		"west" : __DIR__"pingtai",
	]));
	set("objects",([
		WEAPON_DIR+"hammer/muchui" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6210);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}




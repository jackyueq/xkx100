// Room: /d/nanshaolin/xclang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short","ʯ��");
	set("long", @LONG
һ����ʯ���ɵ����ȣ���Χ���ް�������ʯɫ���࣬ʯ��������
̤��ʯ��֮�ϣ��չ�����������Ͼ�벻�ѡ������ˬ�������������㣬
����ʹ�˳��׽�����
LONG );
	set("exits", ([
		"east"      : __DIR__"xctang",
		"northwest" : __DIR__"gygu",	
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

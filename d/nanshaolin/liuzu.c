// Room: /d/nanshaolin/liuzu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǹ�����������ĵط��������ǹ��������⣬���ͣ��زأ���
�������������������ɽ�����ų����Ħ������ݿɣ�����ɮ貣���
����ţ�������̣�������ܵ����� 
LONG );
	set("exits", ([
		"east" : __DIR__"pingtai",
	]));
	set("objects",([
		WEAPON_DIR+"stick/mugun" : 1,
	]));
	set("coor/x", 1810);
	set("coor/y", -6210);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}




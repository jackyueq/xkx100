// Room: /d/lingxiao/weideju.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","���¾�");
	set("long",@LONG
���ǰ����ڵ����ң��Ҿ����Σ�����������ν��̻Իͣ����������
�����ڰ������Ѳ�֪ȥ��ֻʣ����һ����ң�����������ҭҭ�ؿޡ�
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"book",   
	]));
	set("objects", ([  
		__DIR__"npc/yaoniang" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


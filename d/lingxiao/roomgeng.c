// Room: /d/lingxiao/roomgeng.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
����һ�䰲���ľ��ң��������ǵ��������ӹ����ӵķ��䡣���Ϸ�
��һ����ѩ�ķ�����ǽ�Ϲ���һ��������������Ӵ��������룬����
ǽ�ϣ�ӳ��һ�������ｭɽͼ��������ΰ��
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang1", 
	]));
	set("objects", ([  
		__DIR__"npc/geng" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8860);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


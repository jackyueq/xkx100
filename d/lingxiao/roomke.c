// Room: /d/lingxiao/roomke.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG
�����ǿ�����ķ��䡣������ϲ���ռ������������ıڶ���������
��ɫɫ�ĵ����������������󽣣�Ӧ�о��С����߻�����һ����ֵĶ�
������˵��ǰ����������ķ����͸����Ļ�ǹ����˵��ү�����������
�������������ڴ�������һ���¡�
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang2", 
	]));
	set("objects", ([  
		CLASS_D("lingxiao")+"/ke" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8860);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


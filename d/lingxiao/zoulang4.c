// Room: /d/lingxiao/zoulang4.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
����һ�����������ȣ�������������ľ��ң������ǳ���ѧ�ķ��䡣
����������������ͽ���գ��������������һ������������ֻ��������
��ÿ��ǰ����ɨ��
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"north"     : __DIR__"cheng",  
		"south"     : __DIR__"qi", 
		"southwest" : __DIR__"houyuan2", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8840);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


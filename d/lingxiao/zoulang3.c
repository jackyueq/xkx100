// Room: /d/lingxiao/zoulang3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
����һ�����������ȣ����������߶�����������λ������Ͼ;�ס
�ڴ���Χ�����ϲ�ϲ��ѩ��������Ӵ˴�������˵�������������а���
����Ϊ��ɫ������������ѹ����λ����֮�ơ��������в�ϲ���Ѳ��յ�
�ӡ�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"north"     : __DIR__"liao",  
		"south"     : __DIR__"liang", 
		"southeast" : __DIR__"houyuan2", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8840);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


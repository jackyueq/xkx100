// Room: /yangzhou/woshi.c
// Last Modified by Winder on Jul. 20 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
�ش���һ��̴ױ̨�������廨�����֡�һ齴����ǰ��һ���ᣬϵ
�桶�ľ�˽��ͼ�����������(lian)�ʷ����㡣�������������������
�������߳�����һ������Χ���黭��ɴ��������ʽ��ƣ�������ɫ��ᣣ�
���Ҵ���˿�����֮����һС��Ի�������硱�������ʣ�ԧ�챻���ϻ�
��������ɰ���
LONG    
	);
	set("exits",([ /* sizeof() == 3 */
		"west" : __DIR__"waifang",
	]));
	set("item_desc" , ([
		"lian" :"	��       ��\n"
			"	��       ��\n" 
			"	��       ��\n" 
			"	��       ��\n" 
			"	��       ��\n" 
			"	��       ��\n"
			"	��       ��\n",
	]));
	create_door("west", "ɴ����", "east" , DOOR_CLOSED); 
	set("coor/x", 60);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}
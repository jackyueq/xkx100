// Room: /d/lingxiao/zoulang2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
����һ�����������ȡ����¶����������ӵľ����������ǿ������
���ң�����ƺ�æ����ͽ�ܡ��ϱ��������ǵ������ң�����������ܡ�
�����Ǹ�������Ʈ��һ���󷹲˵���ζ��
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"cook",
		"west"  : __DIR__"zhongting",
		"north" : __DIR__"roomke",  
		"south" : __DIR__"roomzhang", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


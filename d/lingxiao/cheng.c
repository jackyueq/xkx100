// Room: /d/lingxiao/cheng.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
���ǳ���ѧ�ķ��䡣����ѧ���������λʦ��һ�����ɰ����ڴ�ʦ
���գ�������λʦ�ֵ��У����Ͱ����ڹ�ϵ��á�ͬʱ��Ϊ�˷�������
�ϲ�������ð��������Σ����԰�������ʧ����ǰ���������ǵĺ�����
���������ܡ��������������ţ�ֻ�����Ϸ���һ��δд��Ĳ���
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang4", 
	]));
	set("objects", ([  
		__DIR__"npc/cheng" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


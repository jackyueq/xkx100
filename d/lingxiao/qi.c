// Room: /d/lingxiao/qi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
����������ķ��䡣�������Ը���ţ�Ϊ��Ʈ�ݡ�ǽ�Ϲ�����׵�
�������ơ������������������飬�ּ����ű��ţ��ߵ��������ݵ�·
�ӣ�������ϡҲ�ܿ��������书�����顣�ձ���һ����ѩ��ҹ��ͼ����
��������һҹ�����˰�����̫����ʮկ�����¡�����ȼ��һ��̴�㣬
ɢ�����񾲵���Ϣ��һ�Ž�β�ٰ������ϣ��������������������Ե���
�֡�
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang4", 
	]));
	set("objects", ([  
		__DIR__"npc/qi" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


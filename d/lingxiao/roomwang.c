// Room: /d/lingxiao/roomwang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","����");
	set("long",@LONG 
��������˵��һ�����ң�����˵��һ�������ҡ����������˻�Բ��
�ƶ�����ôҲվ��ס���������˰˸�÷��׮��һ������������������
������Ծ��ɣ��������ۻ����ҡ������������ǵ�����������������
���Ṧ׿��������������һ����������������ڲ������£�˭Ҳ��֪��
������ôѧ�����ģ�Ҳ�����������������¡�
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang1", 
	]));
	set("objects", ([  
		__DIR__"npc/wang1" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


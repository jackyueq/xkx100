// Room: /d/lingxiao/ting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM; 
#include <ansi.h>;
void create()
{
	set("short", "Ϸ÷ͤ");
	set("long",@LONG 
�����������ǵ�Ϸ÷ͤ������������������ƽʱ��ϲ�����ĵط���
�����︩�Ⱥɽ�����󵱷磬ֻ�����ｭɽ���������һ����������
����һ��ʫ(poem)���ǰ���ү�Ӿƺ��������̽�������������ȴ˵����
ү����ƽ���Ǻ���������˵���Լ����Լ���ͣ���Ҳû����ֱ�����ڰ�
��ү����ǰ�����䡣
LONG);
	set("exits", ([
		"west" : __DIR__"meiroad3",
	])); 
	set("objects", ([ 
		__DIR__"obj/ban" : 3,
	])); 
	set("item_desc", ([
		"poem" : "�̰Ѹ���������ǳ�õͳ���\n",
	]) );
	set("outdoors", "lingxiao");
	set("coor/x", -30980);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


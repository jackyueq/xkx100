// Room: /d/lingxiao/houyuan2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","��԰");
	set("long",@LONG 
�������ŵ��������������ϲ�����ľ����ˡ�һ�����Ҫ��ûʲô
�£��ǲ����������ġ��Ա߼������������дС������Ͼ��Ե�����
ѩ������֮�Σ�һ����÷������������֮�С����������Χ�ֵĸ�ɫ÷
�������Ǳ��з��飬����ǰ��򽣵ļң��ұ��Ƿ������ס����
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"northwest" : __DIR__"zoulang3", 
		"northeast" : __DIR__"zoulang4", 
		"south"     : __DIR__"houyuan1",  
		"north"     : __DIR__"bridge", 
		"west"      : __DIR__"qihan", 
		"east"      : __DIR__"fenghuo", 
	]));
	set("objects", ([ 
	   __DIR__"obj/mei" : 2, 
	]));
	set("coor/x", -31000);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

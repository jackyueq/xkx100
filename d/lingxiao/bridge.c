// Room: /d/lingxiao/bridge.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","С��");
	set("long",@LONG 
����һ������԰���Ƶ�С�ţ�������Ҷ����岨������ˮ�����̣�
�����Եá���������ѩ������֮�ˣ�˷�����֮�ƣ��˴�ȴ�õ�����ů
֮�󣬵���������罭��֮��������ѩ���ء�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"houyuan2",  
		"north"  : __DIR__"book", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8840);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);

}


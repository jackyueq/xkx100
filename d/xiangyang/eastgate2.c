// Room: /d/xiangyang/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
"�����������ǵĶ����ţ�ֻ�������Ϸ����������֡�"HIG"

                      ������
\n"NOR
"�������ɹ��Ŵ��ַ������ǣ�����������൱���ܣ�һЩ�ٱ�
�������̲�Ҫ�������ǵ��ˡ������Ǻܴ�Ĳݵء�\n"
 );
//        set("outdoors", "xiangyang");

	set("exits", ([
		"west"  : __DIR__"eastgate1",
		"east"  : "/d/jianzhong/shanlu1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -440);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
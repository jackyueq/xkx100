// Room: /d/xiangyang/eastgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��������");
	set("long", 
"�����������ǵĶ����ŵ��ڳ��ţ�ֻ�������Ϸ���������
�֡�"HIG"

                      ������
\n"NOR
"�������ɹ��Ŵ��ַ������ǣ�����������൱���ܣ�һЩ�ٱ�
�������̲�Ҫ�������ǵ��ˡ��������ϳ�ͷ��ʯ�ף���������
������\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"southup" : __DIR__"walle1",
		"northup" : __DIR__"walle2",
		"west"    : __DIR__"eastjie3",
		"east"    : __DIR__"eastgate2",
	]));
	set("objects", ([
		__DIR__"task/pi2"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -450);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

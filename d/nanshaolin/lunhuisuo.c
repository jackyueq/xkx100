// Room: /d/nanshaolin/lhsuo.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", HIG"�ֻ���"NOR);
	set("long", @LONG
��һ�ŵſ��ſ�ʱ����������ԭ�������������µĴ󶫲ޡ������
�����ˣ���������ֻ�֮�����������ֺ���ʮ���ڿ죬��ζ���أ�����
���Ǵ�ɨ�÷ǳ��ɾ���
LONG );
	set("exits", ([
		"west" : __DIR__ "songshu2",
        ]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/fangyan" : 1,
        ]));
	set("coor/x", 1830);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


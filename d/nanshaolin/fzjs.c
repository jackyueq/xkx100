// Room: /d/nanshaolin/fzjs.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIG"���ɾ���"NOR);
	set("long", @LONG
����ĵ�������������ŷ�����ʮ���Ʋ����ţ�������һ����ľ��
̳����̳�Ϸ��Ÿ����Ƶ�ľ�㡣�����߸�����һ��������ۼ�Ĵ�ƿ��
�ϲ�̴����֦���������ƣ��뵷ҷ�������һƬ���֮��������������
���ɶ�ɮ�ڽ���˵���ĵط���
LONG );
	set("exits", ([
		"up"   : __DIR__"fzjs1",
		"east" : __DIR__"xiaolu7",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1780);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}


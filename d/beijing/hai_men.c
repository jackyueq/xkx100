// /beijing/hai_men.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","���ι�����");
	set("long", @LONG
����һ����լ����լ�Ĵ��Ž����ر��ţ����Ϲ���һ����ң�����
д�š����ι������ĸ����֣���Ȼ��¹������ͬ�ǹ����������Ǵ�С��
��ͷȴ����ͬ�������Ҷ����ǡ����ι����������Ǻ��֣�һ��Ҳ����
�ۡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"xidan1",
		"south" : __DIR__"hai_dayuan",
	]));

	set("no_clean_up", 0);
	set("coor/x", -230);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// /d/shenlong/zhulin1 ����1
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǰ��һƬ���̵����֣�����������ˣ�һ�����紵������Ҷɳɳ
���졣ż���м������߹������ϻ̳Ͽֵ����ӣ��㲻�ɵõ�����һ����
�����ѹ�����ߵĻ������˻�ȥ��������һ���񷿣���������һƬ���֣�
������һ�����á�
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"west"  : __DIR__"shibanlu",
		"enter" : __DIR__"qianlong",
		"south" : __DIR__"yaofang",
		"north" : __DIR__"zhulin2",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/yin" : 1,
	]));
	setup();

	replace_program(ROOM);
}

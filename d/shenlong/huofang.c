// /d/shenlong/huofang �﷿
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�﷿");
	set("long", @LONG
�����������̵Ļ﷿�����ӵ�һ���Ǹ���¯���Ա���һ����ͷ����
������񣬹��ڲ�֪������ʲô������������ζ�Ѿ�������ð��಻ס
�ˡ�
LONG
	);
	set("exits", ([
		"south" : __DIR__"shibanlu",
	]));
	set("objects",([
		__DIR__"obj/hongcha" : 3,
		__DIR__"obj/shegeng" : 2,
	]));
	setup();
	replace_program(ROOM);
}

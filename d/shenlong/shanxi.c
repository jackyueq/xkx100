// /d/shenlong/shanxi ɽϪ
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽϪ");
	set("long", @LONG
��ɽϪ���У�Ϫˮ���ȣ���ľ���£��ĸ��Ŀ�������������ɽ·��
��������������һ���޼ʵĴ󺣡�
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"northwest" : __DIR__"shanlu1",
	]));
	set("snaketype", ({"shuishe"}));

	setup();
}

#include "snakeroom.h"


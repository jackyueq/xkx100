// /d/shenlong/shanlu2 ɽ·2
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���µ�ϸɳ���������ɽ�ϵ���ʯ��ɽ·�ľ������ŵ�����Ʈ����
�����㣬��������ɾ�������ɽ��С·ǰ�У����ߴ���������У���
���徲�������������ڿ���֮�С�������ɽ�£����������ѵ�ɽ·��
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south"     : __DIR__"shanlu1",
		"northup"   : __DIR__"shanpo1",
		"northeast" : __DIR__"shanqiu",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/zhang" : 1,
	]));
	set("snaketype", ({"snake", "zsnake"}));
	setup();
}

#include "snakeroom.h";


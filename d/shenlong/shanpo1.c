// /d/shenlong/shanpo1 ɽ��1
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ɽ�£�ͨ�򱱷���һ��ɽ�壬�ºܶ����Ṧ���õ�������
���͸��ӷ�����ͻȻ�䣬�㿴�����ϡ����ϡ�·�ϣ���һ������һ��ȫ
�Ƕ��ߣ����¼��ˣ���������һ��ɽ�£�������һ��ɽ·��
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"northup"   : __DIR__"shanpo2",
		"southdown" : __DIR__"shanlu2",
	]));
	set("snaketype", ({"jinhuan", "fushe"}));
	setup();
}

#include "snakeroom.h";

// /d/shenlong/shanqiu ɽ��
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һƬɽ��أ�����������Ҷ�ͻ��������ڸ��¹��꣬����ʮ��
��Ţ��ͻȻ���㷢�ֵ���������߳����еĺۼ�����ϸ������С������
���ӣ����ȷ�Ƴ��ޣ��㲻�ɵû�������һ�㼦Ƥ��񡣱�����һƬ��
԰��
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"north"     : __DIR__"guoyuan",
		"southwest" : __DIR__"shanlu2",
	]));
	set("snaketype", ({"yinhuan"}));
	setup();
}

#include "snakeroom.h";

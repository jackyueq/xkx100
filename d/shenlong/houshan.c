// /d/shenlong/houshan ��ɽ
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
�����Ǻ�ɽ���˼��������Ӳݴ�����ǰ���·Խ��ԽС��·�ϻ���
ʲô���������ĺۼ�����Խ��Խ���£���ʱ��ͷ��ͻȻ���㿴���ݶ���
�ƺ���һ�����������ֿ���̫�����
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"southdown" : __DIR__"kongdi",
		"northdown" : __DIR__"luanshi",
	]));
	set("snaketype", ({"mangshe"}));
	setup();
}

#include "snakeroom.h";

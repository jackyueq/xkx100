// ɽ�� /d/shenlong/shandao
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ת������ɽ�£�����������һ��ɽ��֮�У�ɽ���ı����Ƿ嶥����
����ɽ�¡�̧ͷң���嶥���ż��������ݣ���������ԼԼ���������ϡ�
�ĵ���ײ���������˸���������������������ɽ����Զ�ˡ�ɽ����խ��
ֻ����һ��ͨ����
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"northup"   : __DIR__"fengding",
		"southdown" : __DIR__"shanpo2",
	]));
	set("objects", ([
		__DIR__"npc/old" : 1,
	]));
	set("snaketype", ({"snake", "fushe"}));
	setup();
}

#include "snakeroom.h";

// /d/shenlong/changlang.c ����
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ȣ�����ͨ������������Ƿ嶥����Χ��������Ҷ����
�٣����������Сʯ�ʿɹ�����Ϣ��һЩ�������������������������
�����̵ĵ��ӣ�������������̸����ʲô��
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"east": __DIR__"tingkou",
		"west": __DIR__"fengding",
	]));

	set("objects", ([
		__DIR__"npc/fang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

// /d/shenlong/zoulang.c ����
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʯ���ȣ�����ͨ����������������䳡����������ʯ����
�����������Ҷ�����٣����������Сʯ�ʿɹ�����Ϣ��һЩ������
������������������������̵ĵ��ӣ�������������̸����ʲô��
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south": __DIR__"dating",
		"north": __DIR__"wuchang",
	]));

	set("objects", ([
		__DIR__"npc/mujianping" : 1,
	]));
	setup();
	replace_program(ROOM);
}

// Room: /d/nanshaolin/shifang.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"ʯ��"NOR);
	set("long", @LONG
һ���޴���Ʒ��������Ƭɽ��֮�䣬�Ʒ����Ϸ��������������
�֣������е�һ��ɲ�����ּ���Щ���䣬����ȥ�����Ϊ��Զ�ˡ�ǰ��
��һƬ�ܴ�Ĺ㳡��վ����ǰ���������ͺ�һЩ�����ϵĺ�ʿ������
�������µ�ɽ�ŵ�ʹ����ڹ㳡�ı��ࡣ
LONG);

	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"shanlu3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6320);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


// Room: /d/changcheng/changcheng17.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
���Ѿ��ƹ��˵����ĳ�ǽ���лص��˳����ϡ�վ�ڼ�ʵ�ĳ�ש�ϣ�
����˵ĳ�����������ﳤ�����������������������������ڿտ���ɽ
�ϴ��˺�Զ����Զ��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"westup"    :__DIR__"changcheng18",
		"southdown" :__DIR__"changcheng16",
	]));
	set("no_clean_up", 0);
	set("coor/x", -13000);
	set("coor/y", 11000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
// Room: /d/changcheng/changcheng18.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
���Ѿ��ƹ��˵����ĳ�ǽ���ֻص��˳����ϡ�վ�ڼ�ʵ�ĳ�ש�ϣ�
����˵ĳ�����������ﳤ�����������������������������ڿտ���ɽ
�ϴ��˺�Զ����Զ��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"southwest"  :__DIR__"changcheng19",
		"eastdown"   :__DIR__"changcheng17",
	]));
	set("no_clean_up", 0);
	set("coor/x", -14000);
	set("coor/y", 11000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
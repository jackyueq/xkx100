// Room: /d/changcheng/changcheng3.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�ϵ������ǰ����Ĺ�ľ�ԣ���Ŀ��ȥ������µĳ���˳��ɽ��
��һ�����������ѵ��򶫺����������ȥ����������������ԼԼ����
���������������ľ�ӹ�ء�
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"westup"   :__DIR__"changcheng4",
		"eastdown" :__DIR__"changcheng2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2000);
	set("coor/y", 5000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
// Room: /d/changcheng/changcheng2.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�ϵ������ǰ����Ĺ�ľ�ԣ���Ŀ��ȥ������µĳ���˳��ɽ��
��һ�����������ѵ��򶫡��������ȥ��������������Կ���������
�����ľ�ӹ�ء�
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"westup" :__DIR__"changcheng3",
		"east"   :__DIR__"changcheng1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
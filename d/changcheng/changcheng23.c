// Room: /d/changcheng/changcheng23.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT@LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�ϵ������ǰ����Ĺ�ľ�ԣ���Ŀ��ȥ������µĳ���˳��ɽ��
��һ�����������ѵ������ϺͶ��Ϸ������ȥ����������Ѿ��ܿ���
���Ϸ�Զ���ĺ���һ����ΰ�Ĺس��ˡ�
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"southeast" :__DIR__"shanhaiguan",
		"southwest" :__DIR__"changcheng22",
	]));
	set("no_clean_up", 0);
	set("coor/x", 4000);
	set("coor/y", 6000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
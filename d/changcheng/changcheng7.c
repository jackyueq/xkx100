// Room: /d/changcheng/changcheng7.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�Ͽ��Կ������ٰ����Ĺ�ľ�ԣ������ٵ���Ҳ�������ˣ��ܶ�
�ط��Ѿ�¶����һƬƬ�Ļ�������Ŀ��ȥ������µĳ���˳��ɽ����һ
�����������ѵ��򱱣����������ȥ������ɽ������һ�����̨��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"northup"   :__DIR__"fenghuotai1-1",
		"southeast" :__DIR__"changcheng6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6000);
	set("coor/y", 6000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
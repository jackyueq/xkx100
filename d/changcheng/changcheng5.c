// Room: /d/changcheng/changcheng5.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ�������Ⱥɽ
���ƣ�ɽ�Ͽ��Կ������ٰ����Ĺ�ľ�ԣ����еĵط��Ѿ�¶����һƬƬ
�Ļ����أ���Ŀ��ȥ������µĳ���˳��ɽ����һ�����������ѵ���
�����������ȥ����������������ԼԼ���Կ��������ƺ���һ���ܴ�
�Ĺؿ���
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"     :__DIR__"changcheng6.c",
		"eastdown" :__DIR__"changcheng4.c",
	]));
	set("no_clean_up", 0);
	set("coor/x", -4000);
	set("coor/y", 5000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
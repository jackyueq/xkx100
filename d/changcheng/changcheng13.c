// Room: /d/changcheng/changcheng13.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", WHT @LONG
������Ǿ��������ĩ������ǡ�վ�ڳ����ϣ�����Կ���ɽ������
�����ɽ���Ѿ����ٿ������͹�ľ���ˡ�ɽ�ϴ�Ƭ�ĵط���ͺͺ�ģ���
��ط��Ѿ�¶���˴�Ƭ�Ļ���������µĳ������ѵ��򱱣����������
ȥ��վ��������Ѿ����Ըе�ӭ������Ĵ���д��Ų���ɳ�ӣ�����
�Ǻ��ĳ�ǽҲ����ʴ��������䣬��Զ����һ�γ�ǽ�Ѿ���������ֻ
�������ƹ�ȥ��
LONG
NOR );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"  :__DIR__"fenghuotai2-1",
		"north" :__DIR__"changcheng12",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10000);
	set("coor/y", 8000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
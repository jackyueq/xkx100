// Room: /d/tiezhang/xzfeng.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"Сָ��"NOR);
	set("long", @LONG
���ѵ�����Сָ��ķ嶥����ĿԶ��������Զ���ķ�����û��ŨŨ
������֮�С�����ĸ߶�ǡ������֮�У���ֻ�ܿ�����ǰ���׵ľ��
�����ģ�����·��ѱ�ˮ����ʪ������Ϯ����������ɪɪ������
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"pubu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2070);
	set("coor/y", -1900);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
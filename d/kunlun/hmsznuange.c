// Room: /d/kunlun/hmsznuange.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"ů��"NOR);
	set("long", @LONG
����ɽ��һ��Ϊ���䣬���ڴ�ů��֮��ȴ��ů�紺�����ֲ�����
������̿�𣬴˼�ȡů�������������ޱȡ����г���ԻͲ��ã������
�϶����Ž�����棬���Ǹ����������ϱ��Ǵ�����
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"hmszdating",
	]));
	set("objects",([
		__DIR__"npc/zhu1"   : 1,
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", -90030);
	set("coor/y", 10030);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

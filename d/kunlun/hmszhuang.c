// Room: /d/kunlun/hmszhuang.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"��÷ׯ��"NOR);
	set("long", @LONG
����һ���Ĵ��ׯ�ӡ�һ�ۿ�ȥ��֪���˼������ǵ��صĸ�������
����ɽ������ô���һ��ɽׯȷʵ�ǳ��ټ����ഫ���˼�����Ҳ������
���ˣ�����·��֮��Ҳ��������Ľ��룬���Խ���֮�������
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"north"    : __DIR__"hmszdating",
		"eastdown" : __DIR__"hmszroad2",
		"westdown" : __DIR__"shanxi",
	]));
	set("objects",([
		__DIR__"npc/yao" : 1,
	]));
	set("outdoors", "hongmei");
	set("coor/x", -90030);
	set("coor/y", 10010);
	set("coor/z", 50);

	setup();
	replace_program(ROOM);
}

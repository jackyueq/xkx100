// Room: /d/jueqinggu/sanqingxuan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ���ȹ�����͵ĵط�������ǽ���Ϲ�������鷨ͼ������
���Ը������Σ������ǻ��ȡ�
LONG
	);

	set("exits", ([
		"north"    : __DIR__"shufang",
		"eastdown" : __DIR__"songtang",
		"south"    : __DIR__"jiantan",
		"southwest": __DIR__"huilang1",
	]));
	set("objects", ([
		__DIR__"npc/gongsunzhi" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -360);
	set("coor/z", 20);
	setup();
 
}
int valid_leave(object me, string dir)
{
	if (!me->query("jqg_pass") &&
		present("gongsun zhi", environment(me)) &&
		(dir =="south" || dir =="north" || dir=="southeast"))
		return notify_fail("����ֹŭ�⵽������Ϊ����С��Ů�������Ҿ���������ܣ���\n");
	return ::valid_leave(me, dir);
}

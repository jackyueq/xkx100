// /beijing/weifu_men.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","Τ������");
	set("long", @LONG
������ǵ�����һ�購��������������Ϊ��һ��¹��������Τ��ү
�ľ�լ���������һ�������ûʵĸߴ��������������ǰ��������
������ͷ�ߴ��ʯʨ�ӡ����Ϻ���һ����ң������ǵ����׸���������
��汣�͵����ѧʿ�ױʹ����ġ�¹���������ĸ���ʴ��֡�
    ��ǰվ�Ÿ�Τ����������
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_zoulang1",
		"south" : __DIR__"xisi2",
	]));
	set("objects", ([
		__DIR__"npc/shiwei2" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("shi wei", environment(me))) && dir == "north")
		return notify_fail("�����ȵ������ҹ䣬��ү���첻���͡�\n\n");
	return ::valid_leave(me, dir);
}

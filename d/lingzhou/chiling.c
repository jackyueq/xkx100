// Room: /lingzhou/chiling.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������ǰ��ƽ�Ĳ�����֮���ذϳ�ǵ���Ĺ����Ϊ�����Զ����
��ȥ�е��ưܣ������ʯ�Ʒ�ͷ������С�ݴ�ʯ�������ͷ�������㣬
��ǰ�������ɰص����÷ǳ��ߴ󡣱Ͼ��Ǽ�����ǰ�ֵ�ѽ��
LONG );
	set("exits", ([
		"south"   : __DIR__"wangling",
		"north"   : __DIR__"deling",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	set("coor/x", -17920);
	set("coor/y", 32150);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
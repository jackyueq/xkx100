// wg_shufang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
������ݹ������鷿�����ںܾ�����������Ӵ����������ֱ���
�������ڿ�������һ������ܣ���Ȼ����Щ���˳������顣ǽ�ϸ�����
�������֡���׳��Ŭ�����ϴ�ͽ�˱�����
LONG);
	set("exits", ([
		"north" : __DIR__"wg_lang5",
	]));
	set("objects", ([
		__DIR__"npc/wg_lingxiaodizi" : 1,					
	]));	
	set("coor/x", 31);
	set("coor/y", -50);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

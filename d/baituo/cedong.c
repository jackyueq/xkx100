// Room: /d/baituo/cedong.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "�ප");
	set("long", @LONG
������һ��СС�Ĳප������������ױ̨���ϱ߰ڷ���һЩŮ�˵�
��Ʒ��
LONG	);
	set("exits", ([
		"east" : __DIR__"dongnei",
	]));
	set("objects",([
		__DIR__"npc/jinhua" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -49970);
	set("coor/y", 20040);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

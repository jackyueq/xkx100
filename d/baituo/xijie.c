// Room: /d/baituo/xijie.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������С������֡������и��Ƶ꣬��ǰ�����Ÿ߸ߵ���ˣ�һ��
�಼����ӭ��Ʈ�����ӡ�����ɫ�Ĵ��֡��ơ���
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"west" : __DIR__"bridge",
		"east" : __DIR__"dongjie",
		"north" : __DIR__"jiudian",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
		__DIR__"npc/snaker"  :1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -49990);
	set("coor/y", 19980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/baituo/jiudian.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "�Ƶ�");
	set("long", @LONG
������һ�Ҷ�����ɫ�ľƵ꣬���ڵش�������ɽ���£��Ƶ���Թ�
Ӧ��ζʳƷ�������⡣�����ԭ���Ͷ����������ʣ����ԾƵ�������¡��
�Ƶ껹��Ӫ��ɢװ�Ƶ�ҵ��
LONG	);
	set("exits", ([
		"south" : __DIR__"xijie",
	]));
	set("objects",([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("resource/water", 1);
	set("coor/x", -49990);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


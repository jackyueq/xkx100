// Room: /d/yanping/road3.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ʯ�̾͵ĳ��֡���ƽ����ɽ��ˮ����������ʯ�ֱ�Ҳ��
����崲��ݡ���������ɽ�����ϸ߸ߵ�ʯ�֣�������ѧ�����ˡ�����ͨ
�����ã����߱������š��ϱ߽��ڸߺ�������ש��ǽ��
LONG );
	set("exits", ([
		"west"    : __DIR__"ximen",
		"east"    : __DIR__"road2",
		"northup" : __DIR__"xishan",
	]));
	set("objects", ([
		"/d/village/npc/kid" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1450);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

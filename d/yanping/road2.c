// Room: /d/yanping/road2.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
һ������ʯ�����춫�������ڵ�����̣���С����߱�����ƽ����
�ˣ�����ͨ���Ӹ��š���ƽ����ɽ���������нֵ�ֻ�ȳ�ǽ�԰�������
ǽ���ٽ�һ�࣬��ǽ�ߺ������ǽ�������ˡ�
LONG );
	set("exits", ([
		"west"      : __DIR__"road3",
		"east"      : __DIR__"yanfumen",
		"south"     : __DIR__"yanshoumen",
		"north"     : __DIR__"yamen",
		"northeast" : __DIR__"road1",
	]));
	set("objects", ([
		"/d/village/npc/girl" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1480);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

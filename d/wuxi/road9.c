// Room: /d/wuxi/road9.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "���С��");
	set("long", @LONG
С��ͻȻ��ÿ�������࣬���ߵ���Ҳ���ϡ���ˣ�����ֱ�ӿ���
һ���޼ʵ���Ұ��ǰ��ճ���һ���ܴ�ĳ��ӣ�ԭ�������Ѿ���������
���Ǿ�����ʥ��̩������ſ��ˡ�
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"road8",
		"west"   : __DIR__"taibomiao",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("coor/x", 350);
	set("coor/y", -860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
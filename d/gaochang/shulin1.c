// Room: /d/gaochang/shulin1.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
������������ĳ�������ǰ����������������Թ�֮�ڲ�����
��ָ�����㲻֪��Ҫ������·�ߡ�����ϸ���������ף����׺�ǰ������
·�϶��е������㼣��
LONG
	);

	set("outdoors", "gaochang");
        set("no_drop",1);
	set("exits", ([
		"west" : __DIR__"shulin"+(random(10)+2),
		"east" : __DIR__"shulin2",
		"south" :__DIR__ "road",
		"north" : __DIR__"shulin"+(random(10)+2),
	]));
	set("objects",([
		__DIR__"obj/fake_map" : 1,
		__DIR__"npc/ghost" : 3,
	]));
	set("coor/x", -38000);
	set("coor/y", 11000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
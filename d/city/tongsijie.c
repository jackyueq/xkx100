// Room: /yangzhou/tongsijie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ͨ����");
	set("long",@LONG
ͨ�����ɴ����ʯ���ɣ�������������Ż��������¸���һ����ˮ
�������������ݹ��ã���ǰ����һ��ʯʨ�����Ϲ�һ�Ҷ���ݡ�����
�˵��˶�ӿ�Ų��������Ƿǣ����������һ�ޣ�����ͨ�������涼��
��լ������С�����۴������У�żȻ��һ�����ӽ�����
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"ximen",
		"east"      : __DIR__"caohexiaojie",
		"north"     : __DIR__"yamen",
		"southwest" : __DIR__"caohecexiang",
	]));
	set("objects", ([
		__DIR__"npc/xunbu" : 1,
	]));
	set("coor/x", -20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

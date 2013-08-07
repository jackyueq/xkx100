// Room: /d/wudujiao/wdsl3.c

inherit ROOM;

void create()
{
	set("short", "�嶾ɽ·");
	set("long", @LONG
�������嶾ɽ�е�ɽ��С·�����������������ϡ�ɽ·�ϼž�
������������һ˿���޵ĺۼ�����˳�ֲ�������·�е�֦������֦
��Ȼһ�������˻�ȥ������...����Ȼ��һ�����ƿ�֦�Ķ��ߡ�
LONG
	);
	set("outdoors", "wudujiao");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : "/d/npc/m_weapon/liangoushi",
		"eastup"    : __DIR__"wdsl4",
		"south"     : __DIR__"wandu1",
		"northdown" : __DIR__"wdsl1",
	]));

	set("coor/x", -44970);
	set("coor/y", -81060);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

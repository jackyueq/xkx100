// Room: /yangzhou/caohenanjie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","�ݺ��Ͻ�");
	set("long",@LONG
����ֵ��ȲݺӶ����ĳ���խ�Ķ࣬Ҳ�ɾ�ƽ���Ķ࣬����ϡ�٣�
�Ӱ����ϵ����������ҵ�Ӱ���У�ҡҷ���ˣ��������Եļ�Ϊ�ľ�����
�����е��̾�¥������Ż����գ�����������һ��ʯʨ��������һ��ס
�Ĵ���ǹٻ������˼ҡ�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"menting",
		"east"      : __DIR__"taipingqiao",
		"south"     : __DIR__"heyuan",
		"north"     : __DIR__"caohexiaojie",
		"northwest" : __DIR__"chanzhimenqian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
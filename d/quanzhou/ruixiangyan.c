// Room: /d/quanzhou/ruixiangyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ڰ�ɽ����СϿ���е�һ��ʯƺ�����ϴ˴������ɼ�һ��
Ư���ķ�ľʯ�ҡ�ʯ�Һ���ʵĴ���ʯ�����������塹����ʱһλ�ɽ�
�����ɡ�����Ĳ�᡹��������״������ׯ�ϴ󷽣�ά��άФ��
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"southup"     : __DIR__"wangzhouting",
		"northdown"   : __DIR__"shanlu3",
	]));
	set("objects", ([
		"/d/wudang/npc/monkey" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6430);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

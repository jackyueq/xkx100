// Room: /d/quanzhou/houshanmen.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
�ߵ��ؾ���󣬶���������С�š�����ǿ�Ԫ�µĺ�ɽ�š�������
��������
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southup"     : __DIR__"cangjingge",
		"northeast"   : __DIR__"chenghuangmiao",
	]));
	set("coor/x", 1830);
	set("coor/y", -6460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/yueyang/xijiaochi.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "ϴ�ų�");
	set("long", @LONG
����ϴ�ų������ڶ������£�Ϊ����ʯͷ���¶��ɣ���˵����֮һ
�����������ڴ�ϴ�š������ˮ���ص���̦���¿��ˡ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northup" : __DIR__"langyinting",
	]));
	set("coor/x", -1690);
	set("coor/y", 2280);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}

// Room: /d/baituo/restroom.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","��Ϣ��");
	set("long", @LONG
�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û���ܴ�
�š����������ɵĳ��ȡ�
LONG );
	set("exits",([
		"south" : __DIR__"changlang",
	]));
	set("sleep_room", 1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_clean_up", 0);
	set("coor/x", -50020);
	set("coor/y", 20050);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

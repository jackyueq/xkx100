// Room: /d/heimuya/restroom.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","��Ϣ��");
	set("long", @LONG
�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û���ܴ�
�š����������ɵĳ��ȡ�
LONG );
	set("exits",([
		"east" : __DIR__"houting",
	]));
	set("sleep_room", 1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_clean_up", 0);
	set("coor/x", -3260);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

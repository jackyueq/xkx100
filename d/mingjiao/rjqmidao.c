//RJQMIDAO.C

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
������һ���ص��ľ�ͷ��ʯǽ֮��Ƕ����յ�͵ƣ�����ٿ������ǰ
��ȥ���ڰ��в�֪������
LONG );
	set("exits", ([
		"north" : __DIR__"rjqjiguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 840);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}


// Room: /d/chengdu/xuetao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "Ѧ�ξ�");
	set("long", @LONG
������һ��Ůʫ��Ѧ������֮�����������ֻ��ƣ������ĵ����Լ�
�ĽŲ��������õ��������ǰ�пڹž������泤������̦���������Ѿ�
�ܾ�û�������ˡ�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west" : __DIR__"wanliqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}




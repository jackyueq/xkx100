// Last Modified by Sir on May. 22 2001
// xiuxishi.c ��Ϣ��

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�����Ǻ�ɽ�����ֵ���Ϣ�ҡ����߷ǳ��谵������û��ʲô��Ķ�
����ֻ���м����һ����ʰ����������Ĵ󴲣��м���ҹ�����ֵ�Сʦ
̫����˯����
LONG
	);
	set("exits", ([
		"east" : __DIR__"byawest",		
	]));
	set("no_clean_up", 0);
	set("sleep_room",1);
	set("no_beg",1);
	set("no_fight",1);
	set("no_steal",1);

	set("coor/x", 20);
	set("coor/y", 3210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}


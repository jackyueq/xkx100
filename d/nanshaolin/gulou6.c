// Room: /d/nanshaolin/gulou6.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�ش�������һ����������ɽ�磬������ˡ�¥�ϴ���һ������Ƶ�
������
LONG );
	set("exits", ([
		"up"   : __DIR__"gulou7",
		"down" : __DIR__"gulou5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}


// Room: /d/chengdu/xiaoting.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "Сͤ");
	set("long",@LONG
�����Ǹ��������µ�Сͤ�������ǵ��������ϲ��������������
������ϰϰ���ҿɸ�������������������գ�
LONG
	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest" : __DIR__"funanhe2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8030);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}



//ROOM: /d/huashan/changlang.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
�����ڳ�����ֻ���������ߣ���������������紵����ϸ������
������ɽ�����ɹ�Ȼ�����������������˵ľ��ҡ�
LONG );
	set("exits", ([
		"west"  : __DIR__"jushi",
		"north" : __DIR__"songlin1",
		"south" : __DIR__"garden",
	]));
	set("no_clean_up", 0);
	set("coor/x", -870);
	set("coor/y", 230);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}

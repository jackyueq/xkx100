// Room: /d/songshan/westpath1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǻ��Ƴ��������ȣ������񶰣�ȴҲ������ۼ��һ·��������
��ľ���춯��������ζ�������������ģ��˷���磬ֻ�������������
�䣬��ɽ���������
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"west" : __DIR__"westting",
		"east" : __DIR__"jianchi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

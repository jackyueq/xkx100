// Room: /d/songshan/westpath2.c
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
		"west"  : __DIR__"liangong",
		"south" : __DIR__"westting",
		"north" : __DIR__"westwuchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 910);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ������ɽ������ʱ�ɼ��������˱��Ű��������ŵ���������
ȥ����������೵������ĺۼ���
LONG );
	set("exits", ([
		"south" : __DIR__"xiaowu",
		"north" : __DIR__"nanmen",
		"east"  : __DIR__"shandao4",
		"west"  : __DIR__"shandao2",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2053);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
//RJQMEN.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������һ�����ţ����ֻ�ݵ���һ���˽�����ÿ�����ڵ��ˣ�
�������ʾһ�����ƣ��ſɽ��롣
LONG );
	set("exits", ([
		"enter" : __DIR__"rjqyuan",
		"east" : __DIR__"torjq3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52010);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
// /d/beijing/alley1.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "������ͬ");
	set("long", @LONG
����������ϣ��е��ƺ���Щ����ϱ����ǿյ�����С��������
���������ˡ�������һ����ݡ������������������һ�����紵������
����ס���˸������� 
LONG );
	set("outdoors", "beijing");

	set("exits", ([
		"east" : __DIR__"mianguan",
		"south" : __DIR__"alley2",
		"north" : __DIR__"xichang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/lingxiao/cityout1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����������ǵĳ��⣬����������ǰ���Ǹ��ʵĳ�ǽ�����������
�ӳ����ߣ���ҪԽǽ���룬�ǲ�̫���ܵġ���������Ұ�Ǻܶ࣬���Բ�
��ʲô��ȫ�ĵط������ǸϿ���ǰɡ�
LONG
	);
	set("outdoors", "lingxiao");
	set("exits", ([
		"east" : __DIR__"shanya",
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8940);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

// Room: /d/songshan/chitang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ߵ�ʯ���������������Կ������ص��ǿڴ������������
��С��԰�ˡ��������������Ƶ�������һ�ر�ˮ��������ζ��ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"huayuan",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 910);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

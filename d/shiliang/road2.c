// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����ͨ������ʯ�������ʯ���������ɽ������֮ˮ�����������
�㱱��������һ��ζ�ˡ�
LONG
	);
	set("outdoors", "shiliang");
	set("exits", ([
		"southwest" : "/d/jiaxing/chating",
		"northup"   : __DIR__"road1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1610);
	set("coor/y", -1990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
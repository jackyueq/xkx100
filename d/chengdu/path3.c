// Room: path3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "̶��С·");
	set("long", @LONG
������Ȼ�Ѿ���������������е����⣬�Ծ���ʮ�����ȵġ���
����һƬܽ������Զɽ��������֮�У�������������ˣ���Զ�����ţ�
һ�ԴԵ����֣���һ��Ϫ������������������ȥ���������У������з�
��֮��˼���������Ȼ֮������
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest"  : __DIR__"path4",
		"southeast"  : __DIR__"path2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

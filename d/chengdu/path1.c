// Room: path1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "Ϫ��С·");
	set("long", @LONG
������Ȼ�Ѿ���������������е����⣬�Ծ���ʮ�����ȵġ���
����һƬܽ������Զɽ��������֮�У�������������ˣ���Զ�����ţ�
һ�ԴԵ����֣���һ��Ϫ������������������ȥ��
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"northeast"  : __DIR__"path2",
		"southwest"  : __DIR__"xiaoxiang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

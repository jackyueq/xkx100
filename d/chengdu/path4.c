// Room: path4.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "̶��С·");
	set("long", @LONG
������Ȼ�Ѿ���������������е����⣬�Ծ���ʮ�����ȵġ���
����һƬܽ������Զɽ��������֮�У�������������ˣ���Զ�����ţ�
һ�ԴԵ����֣���һ��Ϫ������������������ȥ�����ϱ��ǰٻ�̶��
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"northeast"  : __DIR__"path3",
		"southwest"  : __DIR__"baihuatan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

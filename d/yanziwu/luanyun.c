// Room: /d/yanziwu/luanyun.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ��������ɽ�嶥�ϡ������︩������⣬�����۴���֯��
����ɽׯ��Ƕ�����겨���У�ǡ��ˮ������һö���ݡ�
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown"   : __DIR__"path24",
	]));
	set("coor/x", 1210);
	set("coor/y", -1240);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
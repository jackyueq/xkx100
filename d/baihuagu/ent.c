// Room: /d/baihuagu/ent.c
// Last Modified by Winder on Mar. 5 2001

inherit ROOM;
void create()
{
	set("short", "С·");
	set("long", @LONG
����һ����С·��������Ũ���Ĵ�ɭ�֣���֪�����ȥ֮��
���ܲ��ܳ��������������ţ���������������
LONG);
	set("outdoors", "baihuagu");
	set("exits", ([ 
		"north" : __DIR__"tree",
		"southeast" : "/d/jianzhong/shanlu2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/baihuagu/out.c
// Last Modified by Winder on Mar. 5 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
��ǰһƬ����������������ĺڰ�����ֱ�е���ۡ��ϱ���һ
Ƭ��ɭɭ�Ĵ����֣��������ǲ����ٽ�ȥ�ˡ�
LONG);
	set("outdoors", "baihuagu");
	set("exits", ([ 
		"south" : __DIR__"tree",
		"north" : __DIR__"bhgent",
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

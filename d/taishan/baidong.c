// Room: /d/taishan/baidong.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ض�");
	set("long", @LONG
���ߵ���������Űؼе���Ũ�����죬�����������붴Ѩ������
�Ŀ�����������ˣ�������������������⡰�ض�����
LONG );
	set("exits", ([
		"northup" : __DIR__"sihuaishu",
		"south"   : __DIR__"dengxian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 630);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

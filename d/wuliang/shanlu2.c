// Room: /wuliang/shanlu2.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ͨ����ɽ��С·�����߶���ï�ܵĳ��ݺ����֡�ż����
С��ɹ����ּ�ʱ������һ��Ұ�޵�˻�������ϵ�¹����
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"shanlu1",
		"northup"   : __DIR__"shanlu3",
	]));
	set("coor/x", -71000);
	set("coor/y", -80000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
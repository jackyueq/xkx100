// Room: /wuliang/shanlu1.c
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
		"eastdown" : "/d/dali/shanlu4",
		"westup"   : __DIR__"shanlu2",
	]));
	set("coor/x", -70000);
	set("coor/y", -80000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
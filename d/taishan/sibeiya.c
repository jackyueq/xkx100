// Room: /d/taishan/sibeiya.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "˹����");
	set("long", @LONG
��Ů�ز��о�ʯ����������������˲�־¡�⡰������������˹׭
�顶̩ɽ��ʯ����Ƕʯ�ڣ��׳�˹���¡�
LONG );
	set("exits", ([
		"south" : __DIR__"yunuchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 780);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}

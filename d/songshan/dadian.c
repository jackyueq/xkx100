// Room: /d/songshan/dadian.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������ż䣬������䣬�����е�ʽ�ݶ����������߳߸ߵ�̨��
�ϣ�������ΰ������й���������������
LONG );
	set("exits", ([
		"northup" : __DIR__"shandao1",
		"south"   : __DIR__"chongsheng",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/lu": 1,
	]));
	set("coor/x", 0);
	set("coor/y", 730);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

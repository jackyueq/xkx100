// Room: /d/xiangyang/dingzi.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ֽֿ�");
	set("long", @LONG
�����������Ǳ����Ķ��ֽֿڡ���һֱͨ�������ţ���
���������һ����ֱ����ʯ��֣�ͨ����ڡ�������һ���ϸ�
��ɫ�����ߵĸ�ǽ����������������ʹ���ĵµĸ�ۡ��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"northroad2",
		"west"  : __DIR__"northroad1",
		"north" : __DIR__"northjie",
	]));
	set("coor/x", -510);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
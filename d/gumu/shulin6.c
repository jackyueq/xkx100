// shulin6.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�������У���ֻ����������һ�ɵ������̣����ż���Ļ��㣬��
�����������һȺ���ɫ���۷��������Է�����ȥ���������Ĩ��߾�
��ï�ܵ����֡�
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"west"  : __DIR__"shulin0",
		"east"  : __FILE__,
		"north" : __DIR__"shulin4",
		"south" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", -3190);
	set("coor/y", 80);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

// shulin4.c ����
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
		"east"  : __DIR__"shulin6",
		"west"  : __DIR__"shulin5",
		"north" : __DIR__"kongdi",
		"south" : __DIR__"shulin0",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 80);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

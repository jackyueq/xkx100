// kongdi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
��������ɽɽ������һ��յأ�����ƽ̹������һ��С·ֱ��ɽ�
���ϣ�ͨ��������ɽ���塣�ϱߺ�����һ��Ƭ���֣�ֻ��������������
�д�����������һ��ɽ·�����Ϻ�������һ��С����
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"west"    : __DIR__"shulin5",
		"south"   : __DIR__"shulin4",
		"northup" : __DIR__"shanlu1",
	]));
	set("coor/x", -3200);
	set("coor/y", 90);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

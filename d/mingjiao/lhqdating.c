//lhqdating.c
inherit ROOM;

void create()
{
	set("short", "�һ������");
	set("long", @LONG
�������һ���Ĵ��������к�����չ����ǹӳѪ��������³�ñ��
����ӵס�һ�������ʹ��Ȼ��
LONG);
	set("exits", ([
		"west" : __DIR__"lhqyuan",
	]));
	set("objects", ([
		__DIR__"npc/xinran": 1,
	]));
	set("coor/x", -52020);
	set("coor/y", 1000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
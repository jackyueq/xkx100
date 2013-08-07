// Room: /d/huanggong/donghuamen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ǳ������ڹ�Ա��ƽʱ�����ʹ�֮��. ������������ʯ,
����: ��Ա�˵���������. ����ٹٵ���˵�, �Ĺٱ����½�, ��ٱ�
������, ����Υ��.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"wenhua",
		"south" : __DIR__"dao2",
		"north" : __DIR__"dao3",
	]));
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
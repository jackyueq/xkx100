// Room: /d/jiaxing/guojia.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�������Ѿõ��񷿣��Ҿ߰���һӦ��ȫ��ֻ�Ƕ�����һ���
���������м���һ��С�������ϵı��뻹��û�г�ȥ����������ȥ�ĺ�
��æ��
LONG
	);
	set("exits", ([
		"south" : __DIR__"njroad2",
	]));
	set("no_clean_up", 0);

	set("coor/x", 1570);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
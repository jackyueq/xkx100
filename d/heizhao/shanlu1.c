// Room: /heizhao/shanlu1.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ְ���");
	set("long", @LONG
����������̣��ٲ�̤���ľ��ǰ������ݣ�������·��Ѱ��ÿ
��һ�������������̵�С�ȣ�Ҳ������ʹ������һ��������ľ��
�ܣ���һ��һ���ߵú�����ֻ��һ��̤�գ�����ɽ���ݿ�֮�С�
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);

	set("exits", ([
		"east" : "/d/henshan/hsroad6",
		"west" : __DIR__"shanlu2",
	]));
	set("coor/x", -3000);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// /guanwai/milin2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�ÿ����������
���ı���ϸ���ߴ�ʮ���ɡ�����֦��Ҷ�ܣ��������ȫ��ס���������
�Ե���Щ�谵����ľ֮�䳤�źܶ��ľ�Ӳݣ�ʹ���ߺܼ��ѣ���˵�˲�
����������Щ�Ӳ�֮�С�
LONG );
	set("exits", ([
		"westdown" : __DIR__"milin1",
		"southup"  : __DIR__"milin3",
	]));
	set("objects", ([
		__DIR__"npc/dongbeihu": 1,
	]));
	set("outdoors", "changbai");
	set("coor/x", 6160);
	set("coor/y", 5210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
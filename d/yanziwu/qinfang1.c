//ROOM: /d/yanziwu/qinfang1.c

inherit ROOM;

void create()
{
	set("short", "�߷���");
	set("long",@LONG
�����ǹ�Ľ�����ҵ�����С�ĵط���������ˮ��΢�����������
���Ƶĺɻ�Ҷ�㣬������Ƣ���߷�����˶�����һ��ī��ɫ������ͨ��
¥�ϵ���Ϣ�ҡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"yimen",
		"up"    : __DIR__"qinfang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
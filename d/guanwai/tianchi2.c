// /guanwai/tianchi2.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
���ʮ������������ƣ�������˲Ϣ�����������꣬ʹ��
��ʱ������������������ʱ���������Ө��ɴ��ʱ����Ծ��󺣲��Σ�
��ɫ�������������
LONG );
	set("exits", ([
		"north"    : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5160);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
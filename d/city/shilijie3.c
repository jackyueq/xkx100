// Room: /yangzhou/shiliji3.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ʮ�ﳤ��");
	set("long",@LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ���
�⡣�ϱ��Եúܷ�æ��������һ�������¥�󣬹��š�̫���ŷ硱����
�����Ŷ�������һ�����ң�������¥�����ֲ�������������������ѧʿ
���ֱʡ�������������㴹�����Ρ�������һ����ʽ���ӵ�������
���ƣ��Ǿ�������ѧ��֮������ͬ�����������ˡ�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"wumiao",
		"east"  : __DIR__"zuixianlou",
		"south" : __DIR__"shilijie4",
		"north" : __DIR__"shilijie2",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/ma" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

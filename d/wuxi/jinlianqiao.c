// Room: /d/wuxi/jinlianqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ������ʯ�ţ�ÿ������ʯ������̨�������ǰ˸���ñ���й�
��ͷ���ͷ���ĸ�������ʯ�Ͽ̵ġ�ͯ�Ӵ�ĵ����ͼ����������ʯ����
������״������͸��������ɣ������к�Ҷ��ƿ�͹��ȡ�������������
���ȳƣ�������ۼ����Ϫ��ˮ�����������������ϱ��������д�֣���
������������
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"northroad2",
		"south" : __DIR__"northroad1",
	]));
	set("objects", ([
			"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", 370);
	set("coor/y", -780);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
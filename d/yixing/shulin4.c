// Room: /yixing/shulin4.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï
�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�������Ұ
�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG );
	set("outdoors", "yixing");
	set("exits", ([
		"west"  : __DIR__"shulin3",
		"south" : __DIR__"shanlu1",
		"north" : __DIR__"cldamen",
	]));
	set("objects", ([
		__DIR__"npc/dabei" : 1,
	]));
	set("coor/x", 230);
	set("coor/y", -170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

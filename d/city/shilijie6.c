// Room: /yangzhou/shiliji6.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ʮ�ﳤ��");
	set("long",@LONG
�����������ʫ��д�ġ�ʮ�ﳤ���о������������������ɡ���ʮ
�ﳤ�֡����ֿ����ʮ�ɣ���ש�̵أ�����һ��йˮ�������������л�
���������������Ҷ��С������ǹٺӣ�������������������ң���Ӱˮ
�棬ҡҷ���С������ٽֵ����ӹ������ƣ���һ�����ֺŵ�ҩ�̡�����
��һ���ӻ��̡�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"zahuopu",
		"east"  : __DIR__"yaopu",
		"south" : __DIR__"shilijie7",
		"north" : __DIR__"shilijie5",
	]));
	set("objects", ([
		"/d/dali/npc/duanyu" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
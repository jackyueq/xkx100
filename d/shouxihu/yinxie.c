// Room: /yangzhou/yinxie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","���ݳ���");
	set("long",@LONG
���ݳ�������涫��麡������ҦԪ�����ң���������κ֮������
��������Τׯʫ�����(lian)��
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : "
        ��        ��
        ��        ��
        ��        ��
        ɽ        ��
        Ʈ        ��
        ��        ǰ
        ��        ��
\n",
	]));
	set("exits", ([
		"east" : __DIR__"taohuawu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
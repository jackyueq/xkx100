// /guanwai/yuzhu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ʒ����ϣ��з����ͦ�㣬���ͻ��������������´к��һˮ��
�������ߣ�ע����أ����ǹż����صġ�����Ȫ���ˡ�
LONG );
	set("exits", ([
		"north"      : __DIR__"tiyun",
		"northeast"  : __DIR__"baiyun",
	]));
        set("objects", ([
                __DIR__"npc/she" : 1,
        ]));
	set("outdoors", "changbai");
	set("coor/x", 6170);
	set("coor/y", 5160);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
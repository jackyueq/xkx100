// Room: /binghuo/yuanye2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ԭҰ");
	set("long", @LONG
������һƬ�տ���ԭҰ�����ߵÿڸ��������󺹣���������
����һ����ľ���ݣ�ֻ���ͺͺ���ƽ�������ʯ����ɽ���ڱ��滹Զ
���ء�
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"south"  : __DIR__"yuanye2",
	]));
	set("objects", ([
		"/d/emei/obj/liuhuang" : 1,
	]));
	setup();
	replace_program(ROOM);
}


// Room: /binghuo/yuanye1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ԭҰ");
	set("long", @LONG
������һƬ�տ���ԭҰ�����ض��ǲ�֪����Ұ�ݣ�ƽ�����𡣲�
��֮�г���С�޳�û�����˲�����������һƬ�����֣�����һƬ����
�أ�����Զ���Ļ�ɽ�ڡ�
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"southwest"  : __DIR__"shulin3",
		"southeast"  : __DIR__"caodi2",
		"northeast"  : __DIR__"shulin4",
		"north"      : __DIR__"yuanye2",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 1,
	]));
	setup();
	replace_program(ROOM);
}


// Room: /d/nanshaolin/shulin1.c
// Last Modified by winder on May. 29 2001
// ����Ҳ��ȥ����ƺ�ĵط������������ֿ��Բ�Ҫ��

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ��
���ɡ��������գ��������ڵ�˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ
�Ų���ȥ������β�������
LONG );
	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
/*
		"east"  : __DIR__"shulin"+(random(10)+2),
		"west"  : __DIR__"shulin2",
		"south" : __DIR__"shanlu8",
		"north" : __DIR__"shulin"+(random(10)+2),
*/
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6010);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}


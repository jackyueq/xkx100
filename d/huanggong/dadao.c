// Room: /d/huanggong/dadao.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����ͨ�����еĴ��. ����ԶԶ��������ũ̳. ������һƬ�Գ�, 
�ǻʼҵ�������. ÿ����϶���ȥ����. ƽʱ�ͱȽ�����, ������Щ��
����, �ֵø�����.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 2 */
		 "west" : __DIR__"lie1",
		 "east" : __DIR__"humen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -250);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
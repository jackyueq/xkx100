// Room: /beijing/xichang2.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ڽ��ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ����������
�����ţ�ֱͨ�����⡣�����ǿյ����Ľֵ����ϱ���һ������ϡ�ٵ�С
�����ͨ��������
LONG );
        set("outdoors", "beijing");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xichang1",
		"west"  : __DIR__"ximen",
		"south" : __DIR__"alley1",
		"north" : __DIR__"xidan",
	]));
	set("coor/x", -220);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

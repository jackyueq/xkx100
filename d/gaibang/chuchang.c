// chuchang shi

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ؤ��Ĵ����ң�������ֻ�ܿ���һ�������ŵ����ӡ�
LONG );
	set("exits", ([
		"west" : __DIR__"mishi",
		"east" : __DIR__"undertre",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}

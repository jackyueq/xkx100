//  Room: /d/luoyang/road11.c

inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ���·���ߣ���һ
���Ÿ���������֮�⣬����һƬƬ��ũ���ˡ��������ͨ��֬��֮����
���ݣ�����������ͨ�������ǡ�
LONG);
	set("exits", ([  /*  sizeof()  ==  2  */
		"east" : __DIR__"road10",
		"west" : __DIR__"road0",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

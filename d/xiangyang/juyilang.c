// Room: /d/xiangyang/juyilang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ˮ������");
	set("long", @LONG
����һ����ֱ�����ȣ�������һ����ˮ����ˮӳ�ų�����
���������峺�����ܿ���һЩ����������ȥ���������һ����
��԰��԰�ڶ����������һ���᷿��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"juyihuayuan",
		"north" : __DIR__"juyiyuan",
	]));
	set("coor/x", -530);
	set("coor/y", -502);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

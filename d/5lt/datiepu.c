// Room: /d/5lt/datiepu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬ
ͨ�죬��һ�߽�ȥ���͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ�
����������������ذ�ס����׵��һλ������ͷ�󺹻�����������ר
����־���ڴ�����
LONG );
	set("exits", ([
		"east" : __DIR__"sroad3",
	]));
        set("objects", ([
		__DIR__"npc/smith": 1,
	]));
	set("coor/x", -160);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/suzhou/datiepu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬ
ͨ�죬��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵���
������������ذ�ס����׵��һλ������ͷ�󺹻�����������ר����
־���ڴ�����
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
        set("objects", ([
		"/d/city/npc/smith": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 890);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


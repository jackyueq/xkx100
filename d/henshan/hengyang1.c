// Room: /d/henshan/hengyang1.c
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������ʯ�̾͵���С�ֵ��ϡ�����ʱ�����˳ֽ����У��ƺ�����
����ɶ���ˡ��ϱ���һ��С�꣬����һ������Ρ�룬���ܵ��ߣ��ſڲ�
�Ƹ������ܼҼҶ��������������ˡ�
LONG );
	set("outdoors", "hengyang");
	set("exits", ([
		"east"   : __DIR__"hengyang",
		"west"   : __DIR__"hsroad4",
		"south"  : __DIR__"shop",
		"north"  : __DIR__"liufugate",
	]));

        set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
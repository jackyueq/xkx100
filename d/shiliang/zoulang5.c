// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩�������������ĵ�ס���������Ǻ�Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "northwest" : __DIR__"houyuan",
            "north"     : __DIR__"zoulang6",
            "southwest" : __DIR__"dating",
            "east"      : __DIR__"fang3",
	]));
	set("coor/x", 1620);
	set("coor/y", -1940);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
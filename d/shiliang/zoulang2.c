// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩����������������ס���������Ǻ�Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "east"  : __DIR__"houyuan",
            "north" : __DIR__"zoulang3",
            "south" : __DIR__"zoulang1",
            "west"  : __DIR__"fang2",
	]));
	set("coor/x", 1600);
	set("coor/y", -1930);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
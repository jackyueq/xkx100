// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩���������������ס���������Ǻ�Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "west"  : __DIR__"houyuan",
            "north" : __DIR__"zoulang7",
            "south" : __DIR__"zoulang5",
            "east"  : __DIR__"fang4",
	]));
	set("coor/x", 1620);
	set("coor/y", -1930);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
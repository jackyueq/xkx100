// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩�������Ǽ��鷿�������Ǻ�Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "southwest" : __DIR__"houyuan",
            "northwest" : __DIR__"zoulang4",
            "south"     : __DIR__"zoulang6",
            "east"      : __DIR__"shufang",
	]));
	set("coor/x", 1620);
	set("coor/y", -1920);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
������һ�������������ϣ������������������������������
�䣬�����泩�����������϶���ס���������Ǻ�Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "northeast" : __DIR__"houyuan",
            "north"     : __DIR__"zoulang2",
            "southeast" : __DIR__"dating",
            "west"      : __DIR__"fang1",
	]));
	set("coor/x", 1600);
	set("coor/y", -1940);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
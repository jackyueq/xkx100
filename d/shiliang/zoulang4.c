// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "���Ⱦ�ͷ");
	set("long", @LONG
���������ȵľ�ͷ��������ȥ�Ǻô��һ��������ǰ���и�
Сͤ�������ֵܻ�������ܡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
            "north"     : __DIR__"tingzi",
            "southeast" : __DIR__"zoulang7",
            "south"     : __DIR__"houyuan",
            "southwest" : __DIR__"zoulang3",
	]));
	set("coor/x", 1610);
	set("coor/y", -1910);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
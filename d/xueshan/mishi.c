//      mishi.c ����

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
����һ��С���䡣ʲô������û�С�
LONG );
        set("exits",([
                "south" : __DIR__"midao",
                "down" : "/d/city/shilijie4" ,
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70010);
	set("coor/y", -19870);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
//      hubian4.c ����С·

inherit ROOM;

void create()
{
        set("short","����С·");
        set("long",@LONG
����ʥ���ߵ�С·��·�೤��û��, ���̿�ϲ��
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "north" : __DIR__"shanjiao",
                "south" : __DIR__"hubian3",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -29990);
	set("coor/y", -7990);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
// Room: /d/wudujiao/huating2.c

inherit ROOM;

void create()
{
        set("short", "�ܷ�ͤ");
        set("long", @LONG
������һ����԰�е�Сͤ�ӣ�������������ɫ���㡣ͤ�ӵ������ż���ľ�ˡ�
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "west" : __DIR__"huayuan2",
                "north" : __DIR__"huating1",
        ]));
        set("objects", ([
                 "/d/shaolin/obj/mu-ren": 4,
        ]));

	set("coor/x", -44890);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
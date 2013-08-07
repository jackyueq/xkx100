// Room: /d/wudujiao/minju5.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这是一户普通的农家，屋里没有什么象样的摆设。墙边摆放着一些
农具，除此只外四壁皆空，看来并不富裕。
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun6",
        ]));
        set("objects", ([
                  __DIR__"npc/cunmin": 1,
                  __DIR__"npc/cunfu": 2,
        ]));

	set("coor/x", -44960);
	set("coor/y", -81030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
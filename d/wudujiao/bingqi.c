// Room: /d/wudujiao/bingqi.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������嶾�̴�������ĵط������濿ǽȫ�Ǳ����ܣ����������
���ֱ�����
LONG
        );

        set("exits", ([
                "east" : __DIR__"beiyuan",
        ]));
        set("objects", ([
                  __DIR__"obj/ganggou": 2,
                  __DIR__"obj/woodjian": 2,
                  __DIR__"obj/tiechui": 2,
        ]));

	set("coor/x", -44930);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
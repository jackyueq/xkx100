// Room: /d/wudujiao/minju1.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һЩ
ũ�ߣ�����ֻ���ıڽԿգ�����������ԣ��
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun2",
        ]));
        set("objects", ([
                __DIR__"npc/cunmin": 1,
                __DIR__"npc/cunfu": 1,
        ]));

	set("coor/x", -44980);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
// Room: /d/wudujiao/minju2.c

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
                "out" : __DIR__"cun3",
        ]));
        set("objects", ([
                __DIR__"npc/cunfu": 2,
        ]));

	set("coor/x", -44970);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
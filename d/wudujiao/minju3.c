// Room: /d/wudujiao/minju3.c

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
                "out" : __DIR__"cun4",
                "west" : __DIR__"minju8",
        ]));
        set("objects", ([
                __DIR__"npc/cuilan": 1,
        ]));

	set("coor/x", -44960);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
// Room: /d/wudujiao/minju6.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һЩ
ũ�ߣ�����ֻ���ıڽԿգ�����������ԣ�������ƺ���һ��СԺ��
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun6",
                "south" : __DIR__"minju10",
        ]));
        set("objects", ([
                __DIR__"npc/girl": 1,
        ]));

	set("coor/x", -44940);
	set("coor/y", -81030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
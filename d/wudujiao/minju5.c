// Room: /d/wudujiao/minju5.c

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
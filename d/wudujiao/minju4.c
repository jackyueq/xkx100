// Room: /d/wudujiao/minju4.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һЩ
ũ�ߣ������а���һ�Ű��������峤�����ź��̴��������߳��š�
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun5",
        ]));
        set("objects", ([
                __DIR__"npc/cunzhang": 1,
        ]));

	set("coor/x", -44950);
	set("coor/y", -80990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
// Room: /d/wudujiao/damen.c

inherit ROOM;

void create()
{
        set("short", "�嶾�̴���");
        set("long", @LONG
������һ����û��ɽ���еĴ�լԺ���߸ߵ�Χǽ�����Ĵ��ţ�
������һ����Ǯ�˼ҵı����Ժ��
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"lianwu",
                "west" : __DIR__"wdsl7",
        ]));
        set("objects", ([
                __DIR__"npc/jiaotu": 4,
        ]));

	set("coor/x", -44930);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
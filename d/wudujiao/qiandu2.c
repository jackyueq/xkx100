// Room: /d/wudujiao/qiandu2.c

inherit ROOM;
string* npcs = ({
        __DIR__"npc/qiandu1",
        __DIR__"npc/qiandu2",
        __DIR__"npc/qiandu3",
        __DIR__"npc/qiandu4",
        __DIR__"npc/qiandu5",
});

void create()
{
        set("short", "ǧ����");
        set("long", @LONG
������һ����Ȼ�γɵ�ʯ�������������󡣶������������
����ʯ����ʱ���������δ��ˮ�������ڶ��У�����������ʪ����
�Ժ�Ȼ����һ�����С���������
LONG
        );

        set("exits", ([
              "south" : __DIR__"qiandu1",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));

        set("coor/x", -44960);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}


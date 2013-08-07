// Room: /d/wudujiao/baidu2.c

inherit ROOM;
string* npcs = ({
        __DIR__"npc/baidu1",
        __DIR__"npc/baidu2",
        __DIR__"npc/baidu3",
        __DIR__"npc/baidu4",
        __DIR__"npc/baidu5",

});

void create()
{
        set("short", "�ٶ���");
        set("long", @LONG
������һ����Ȼ�γɵ�ʯ�������������󡣶������������
����ʯ����ʱ���������δ��ˮ�������ڶ������������ʪ����
�Ժ�Ȼ����һ�����С���������
LONG
        );

        set("exits", ([
                "north" : __DIR__"baidu1",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));

        set("coor/x", -44960);
	set("coor/y", -81080);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}


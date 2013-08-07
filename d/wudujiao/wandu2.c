// Room: /d/wudujiao/wandu2.c

inherit ROOM;
string* npcs = ({
        __DIR__"npc/wandu1",
        __DIR__"npc/wandu2",
        __DIR__"npc/wandu3",
        __DIR__"npc/wandu4",
        __DIR__"npc/wandu5",
});

void create()
{
        set("short", "�򶾿�");
        set("long", @LONG
������һ����Ȼ�γɵ�ʯ�������������󡣶������������
����ʯ����ʱ���������δ��ˮ�������ڶ��У�����������ʪ����
�Ժ�Ȼ����һ�����С��������������ƺ����и�Сһ���֧����
LONG
        );

        set("exits", ([
              "south" : __DIR__"wandu3",
              "north" : __DIR__"wandu1",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
        ]));

        set("coor/x", -44970);
	set("coor/y", -81100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}


// Room: /d/wudujiao/bianzhai2.c

inherit ROOM;

void create()
{
        set("short", "��կ����");
        set("long", @LONG
���������置�ؽ磬ֻ����ɽ��ˮ�㣬�羰����ԭ����ͬ��
����·�ϣ���ʱ������������Ů��·����Ұ���ظ����裬�پ���
���泩����Ը���ϴ��硣
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"bianzhai1",
                "south" : __DIR__"bianzhai3",
        ]));
        set("objects", ([
                 __DIR__"npc/younggirl": 2,
                 __DIR__"npc/youngboy": 1,
        ]));

	set("coor/x", -46010);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
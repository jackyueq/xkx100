// Room: /d/wudujiao/huxue1.c

inherit ROOM;

void create()
{
        set("short", "��Ѩ");
        set("long", @LONG
�����Ǹ���������������Ҷ���������ζ�˱ǣ��洦���ǳ�ʣ��
�޹ǡ���ֻ�������ݵĴ��ϻ������ڶ���������ɹ̫����
LONG
        );
        set("exits", ([
                "south" : __DIR__"huxue2",
                "out"   : __DIR__"milin7",
        ]));
        set("objects", ([
                __DIR__"npc/laohu": 2,
        ]));

        set("coor/x", -45000);
	set("coor/y", -80000);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}


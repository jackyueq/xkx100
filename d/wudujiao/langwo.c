// Room: /d/wudujiao/langwo.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������е�һ����������������ζ�˱ǣ��洦���ǳ�ʣ��
�޹ǡ���ֻ�ݵ�Ƥ����ͷ�Ķ��������Ӿ����ƺ�Ҫ��ȥ��ʳ�ˡ�
LONG
        );

        set("exits", ([
                "out" : __DIR__"milin4",
        ]));
        set("objects", ([
                __DIR__"npc/wolf1": 2,
                __DIR__"npc/wolf2": 1,
        ]));

	set("coor/x", -45000);
	set("coor/y", -80100);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}
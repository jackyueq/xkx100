// Room: /d/wudujiao/minju9.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������ڵͰ��Ĺ������棬���ܵ������ǻҳ���֩������
��һ̧ͷ�ͻ��������档�������ܱ�����Ĳ�����ס�ˣ��㿴��
����������������Ҳ���ֲ����㡣
LONG
        );

        set("exits", ([
                "out" : __DIR__"minju7",
        ]));
        set("objects", ([
                  __DIR__"npc/zhanglang": 1,
        ]));
        set("coor/x", -44929);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}


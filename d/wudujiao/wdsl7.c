// Room: /d/wudujiao/wdsl7.c

inherit ROOM;

void create()
{
        set("short", "�嶾ɽ·");
        set("long", @LONG
�������嶾ɽ�е�ɽ��С·�����������������ϡ�ɽ·�ϼž�
������������һ˿���޵ĺۼ�����˳�ֲ�������·�е�֦������֦
��Ȼһ�������˻�ȥ������...����Ȼ��һ�����ƿ�֦�Ķ��ߡ�ǰ��
�ֳ�һ�����ߺ�ǽ������������լԺ��
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"damen",
                "west" : __DIR__"wdsl6",
        ]));

	set("coor/x", -44940);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
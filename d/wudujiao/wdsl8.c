// Room: /d/wudujiao/wdsl8.c

inherit ROOM;

void create()
{
        set("short", "�嶾ɽ·");
        set("long", @LONG
�������嶾ɽ�е�ɽ��С·�����������������ϡ�ɽ·�ϼž�
������������һ˿���޵ĺۼ�����˳�ֲ�������·�е�֦������֦
��Ȼһ�������˻�ȥ������...����Ȼ��һ�����ƿ�֦�Ķ��ߡ�
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "westdown" : __DIR__"wdsl5",
                "south" : __DIR__"sl1",
        ]));

	set("coor/x", -44940);
	set("coor/y", -81060);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
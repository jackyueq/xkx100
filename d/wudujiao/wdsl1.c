// Room: /d/wudujiao/wdsl1.c

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
                "eastup" : __DIR__"wdsl2",
                "southup" : __DIR__"wdsl3",
                "west" : __DIR__"taohua",
        ]));

	set("coor/x", -44970);
	set("coor/y", -81050);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
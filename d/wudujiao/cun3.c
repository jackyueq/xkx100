// Room: /d/wudujiao/cun3.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����С���ʯ��·�ϣ����Զ�������ʯ���ɵķ��ݡ������ﾲ���ĵģ�
���������ˣ�ż������һ�������С�
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"cun4",
                "west" : __DIR__"cun2",
                "north" : __DIR__"minju2",
        ]));

	set("coor/x", -44970);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
// Room: /d/wudujiao/cun6.c

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
                "northwest" : __DIR__"cun4",
                "northeast" : __DIR__"cun7",
                "southwest" : __DIR__"minju5",
                "southeast" : __DIR__"minju6",
        ]));

	set("coor/x", -44950);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
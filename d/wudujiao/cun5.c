// Room: /d/wudujiao/cun5.c

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
                "southwest" : __DIR__"cun4",
                "southeast" : __DIR__"cun7",
                "north" : __DIR__"minju4",
        ]));

	set("coor/x", -44950);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
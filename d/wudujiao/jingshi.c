// Room: /d/wudujiao/jingshi.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���谵�ķ��䣬���˼��Ŵ�֮��ʲô��û�С����ڹ��߻谵����
���ɵĴ���һ����Ƿ��
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
	set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"dating",
        ]));

	set("coor/x", -44910);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
// Room: /d/wudujiao/xiao1.c

inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
�������һ����ߵ�һ������С·��һ�Ծ����峺�Ľ�ˮ���а�
���಻�ϵ��һ�������ϼ������Ϯ�ˣ���������۷��ڻ�������衣
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"xiao2",
                "north" : __DIR__"jiang2",
        ]));

	set("coor/x", -45000);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
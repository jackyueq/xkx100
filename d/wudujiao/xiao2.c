// Room: /d/wudujiao/xiao2.c

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
                "southeast" : __DIR__"xiao3",
                "north" : __DIR__"xiao1",
        ]));

	set("coor/x", -45000);
	set("coor/y", -81030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
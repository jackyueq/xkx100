// /d/xiakedao/road1.c ���͵� ɽ·1

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������ʯ�̳ɵ�С·�ϣ��Ų�ʮ����ݡ����Զ������֣�֦Ҷ��
����գ��������ĺܲ������������ȸߴ����������ķ������һƬ��
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup" : __DIR__"road2",
                "northdown" :__DIR__"shanmen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -22020);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
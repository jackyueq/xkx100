// Room: /d/wudujiao/road3.c

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
����һ�����ϵĻ��������Զ����Լ����һƬ���̵�ɽ�͡�
·��������ϡ����������·Խ��Խխ����Щ�ط���������һ
ƬƬ���Ӳݡ������ƺ���һ����·��
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southeast" : __DIR__"xiaolu",
                "south"     : __DIR__"shanlu1",
                "north"     : __DIR__"road2",
        ]));

	set("coor/x", -45000);
	set("coor/y", -78000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
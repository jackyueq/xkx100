// Room: /d/wudujiao/shanlu1.c

inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
һ�����ѵ�С·����ɽ����ǰ���죬������Ũ�ܵ����֣���
������᫲�ƽ��ɽ·��ǰ����ǿ��µĺ�ɭ���ˡ��Ա��ƺ���һ
��ɽҰС�꣬·����һ��ʯ��(bei)��
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"milin1",
                "west" : __DIR__"xiaodian",
                "north" : __DIR__"road3",
        ]));

        set("item_desc",([
            "bei":"           ǰ����ɭ��ɽ�����ܣ�����֮�ڲ������̣�\n
           �л��ǳ�û���У���������˼�����У�\n",
        ]));

	set("coor/x", -45000);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
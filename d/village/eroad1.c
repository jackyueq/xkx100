// Room: /d/village/eroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ�����һ����ʯ·������ͨ����ӵ����ģ�
�������ǳ����·�ˡ�������һ��ܼ�ª�Ĳ��
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "south" : __DIR__"ehouse1",
            "east"  : __DIR__"eexit",
            "west"  : __DIR__"eroad2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "village");

	set("coor/x", -940);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

// Room: /d/village/ehouse2.c

inherit ROOM;

void create()
{
        set("short", "��լ");
	set("long", @LONG
����һ��ܽ�ʵ�ķ��ӣ���ȻҲ�Ǽ��������������ĳ�����ıȴ���
������������Ҫ�úܶࡣǽ�Ϲ��š����°���һЩũ�ߡ�
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" :__DIR__"eroad2",
        ]));
        set("objects", ([
                __DIR__"npc/dibao": 1
        ]) );
//        set("no_clean_up", 0);

	set("coor/x", -950);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 
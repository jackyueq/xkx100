// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�����Ǹ������ʯ�ң��и��������ڵ��ϣ��Աߵ���յ�綹
���͵ƣ���������ߣ��㿴��ʯ�����м��ٷ��������̳ɵļ�ª
���Σ�ÿ�����ξ�����ͬ������Ͷ�㣬�������䡣�㰤�ο�ȥ��
�������鶼��ͼ�Σ�������Ϊ���⡣
LONG
        );
        set("exits", ([
                "up" : __DIR__"shandong7",
 //               "east" : __DIR__"jinshedong1",
        ]));
        set("objects", ([
                __DIR__"npc/jinshe" : 1,
        ]));
        set("coor/x", 1600);
	set("coor/y", -1980);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}

// beijie.c ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ���������Ľֵ���ÿ���һʮ�壬��Ҫ���������
Щ���֮��ľۻᡣ�ֱ�����һ�Ҿ�¥��¥ǰ����һ������������
д�˸����ġ��ơ��֡�������һ���˼ҡ�����С���ڽ���Ц����
�Ż���׷��
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "south" : __DIR__"zhongxin",
                "north" : __DIR__"jiulou1",
                "west"  : __DIR__"minju1",
        ]));
        set("objects", ([
                __DIR__"npc/kid" : 3,
        ]));

	set("coor/x", -3150);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

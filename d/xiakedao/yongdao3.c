// /d/xiakedao/yongdao3.c ���͵� ��3

inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
�������������࣬�����Ǽ��Ҵ�����������в������µ��ӡ�
����˶��ֳ�ʳ����߱߳ԣ�Ω�ֵ�����ʱ�䡣�����������ڵ���ؤ
����ǽ����Ȼ��˯��һ��С������ż⣬������ӵ��͡�
LONG );
        set("exits", ([
                "south" : __DIR__"shimen",
                "north" : __DIR__"dating",
        ]));
        set("objects", ([
                __DIR__"npc/tongzi" : 1,
        ]));
	set("coor/x", -3080);
	set("coor/y", -22120);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
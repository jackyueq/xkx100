// shenheyuan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���ԭ");
        set("long", @LONG
�˴�λ�����ɽ�в��Ĵ仪ɽ������������ȥ��ֻ��һƬ̹����
��Ĵ�ƽԭ������Ⱥɽ֮�䡣��˵�̳�ĩ�꣬�������ʱ���������
��ʱ�����ݶ�ȱ���ڴ˻�����Ϻ�֮���������������������Ϊ���
ԭ�������Ϻͱ��ϸ���һƬ���֡�������һ���ż���
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "west"      : __DIR__"foyezhang",
                "north"     : __DIR__"shulin3",
                "southeast" : __DIR__"shulin2",
        ]));
        set("objects", ([
                "/d/hanzhong/npc/seller": 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 70);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}

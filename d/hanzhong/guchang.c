// guchang.c ɹ�ȳ�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɹ�ȳ�");
        set("long", @LONG
�����Ǵ�ׯ���ĵ�ɹ�ȳ����ط����󣬲�������Ҳ���塢������
�ң��ֵĹ���Ҳ��ɹ�ˡ����������ջ�ļ��ڣ��ȳ��ж����˹��ӣ�
������Ůͯ�����ڳ������֣���ʱ������һ�������໥��ȥ��
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "southeast" : __DIR__"xiaocun",
                "north" : __DIR__"cunzhangjia",
                "northwest" : __DIR__"minju3",
                "southwest" : __DIR__"minju4",
        ]));
        set("objects", ([
                __DIR__"npc/boy" : 2,
                __DIR__"npc/girl" : 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
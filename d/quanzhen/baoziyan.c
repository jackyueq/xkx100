// /d/quanzhen/baoziyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ·������ɽ·��Խ��Խ�ա�ֻ����ͺͺ��ɽ·�����Ծ��ǹ�ʯ��
��������������Ԩ���첻���ס�ǰ����Զ����һ���ʯ������������
�����ҡ��ٿ����ۣ�����������������֣�����һ�����˱��Ÿ�����
�㣬ϸ�ĺǻ������Ϻ�������һƬ���֡�
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "west"      : __DIR__"shulin2",
                "south"     : __DIR__"shulin1",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/chen": 1,
        ]));

	set("coor/x", -3150);
	set("coor/y", 60);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}

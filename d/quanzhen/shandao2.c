// /d/quanzhen/shandao2.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ�
��������ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼ
һʧ�㣬��Ҫ����������Ԩ�ˡ���������һ����Ŀյء�������ͨ
����ɽ�ţ�ԶԶ��������һ���ϴ�ĺ���
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southup"   : __DIR__"shandao1",
                "northdown" : __DIR__"shulin4",
        ]));

	set("coor/x", -3190);
	set("coor/y", 130);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}

// shandao1.c
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
                "southeast"   : __DIR__"shanlu13",
                "northdown"   : __DIR__"shandao2",
        ]));

	set("coor/x", -3190);
	set("coor/y", 120);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}

// /d/quanzhen/shanlu12.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ�
��������ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼ
һʧ�㣬��Ҫ����������Ԩ�ˡ�������һ����Ŀյء���������һ
����ҡ�
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"    : __DIR__"daxiaochang",
                "southdown"  : __DIR__"juyan",
        ]));

	set("coor/x", -3170);
	set("coor/y", 100);
	set("coor/z", 110);
	setup();
        replace_program(ROOM);
}

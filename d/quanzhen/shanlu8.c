// /d/quanzhen/shanlu8.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�
���ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ����
����ɽ��ع�㣬��������һ����·������������һ�����ѵ�ɽ·��
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"   : __DIR__"shanlu9",
                "southdown" : __DIR__"shanlu4",
        ]));

	set("coor/x", -3130);
	set("coor/y", 10);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}

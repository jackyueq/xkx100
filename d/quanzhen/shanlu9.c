// /d/quanzhen/shanlu9.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�
���ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ����
����ɽ��ع�㡣���������ǽ���������������᫵�ɽ·��
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"   : __DIR__"jinliange",
                "southdown" : __DIR__"shanlu8",
        ]));

	set("coor/x", -3130);
	set("coor/y", 20);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}

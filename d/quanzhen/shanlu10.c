// /d/quanzhen/shanlu10.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�
���ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ����
����ɽ��ع�㣬���������֦ͷ�����䳪�������������������¡���
������һ��ɽ·��
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"    : __DIR__"riyueyan",
                "eastdown"  : __DIR__"jinliange",
        ]));

	set("coor/x", -3140);
	set("coor/y", 30);
	set("coor/z", 60);
	setup();
        replace_program(ROOM);
}

// /d/quanzhen/shanlu13.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ�
���ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ����
����ɽ��ع�㣬���������֦ͷ�����䳪�������������ǲ����¡���
������һ��ɽ·��������һ����Ŀյء�������ͨ����ɽ�¡�
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"     : "/d/gumu/shanlu6",
                "northdown"  : __DIR__"caotangsi",
                "northwest"  : __DIR__"shandao1",
                "eastdown"   : __DIR__"daxiaochang",
        ]));

	set("coor/x", -3180);
	set("coor/y", 110);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}

// /d/quanzhen/shanlu5.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬����
�Դ䣬���ɽ����֦ͷ���񳪺Ͳ����������ɿ���һ����·��������
��ͨ��ɽ�����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "east"      : __DIR__"shanlu4",
                "northwest" : __DIR__"shanlu6",
        ]));

	set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}

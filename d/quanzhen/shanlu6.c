// /d/quanzhen/shanlu6.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬����
�Դ䣬���ɽ����֦ͷ���񳪺Ͳ����������Ͷ��Ͽ�ͨ��ɽ�����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southeast" : __DIR__"shanlu5",
                "west"      : __DIR__"shanlu7",
        ]));

	set("coor/x", -3150);
	set("coor/y", 10);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}

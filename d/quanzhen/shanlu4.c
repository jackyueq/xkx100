// /d/quanzhen/shanlu4.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
�˴�λ�����ɽɽ�š�Ρ�������ɽ���Թ�������������������
����ʥ�ء������������ɽ���������������أ�����Խʮ���أ�
����˰����������������ɽ֮�ơ������ɿ���һ������������
һ��ͨ�����ֵ��ľ�С·��������������ɽ.
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"shanlu8",
                "east"    : __DIR__"puguangsi",
                "west"    : __DIR__"shanlu5",
                "south"   : __DIR__"shanjiao",
        ]));

	set("coor/x", -3130);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}

// Room: /d/5lt/eroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���������
��ʯ·�ϣ�������һ����Ʒ�꣬΢��ϰϰ�������м����ŵı�����ζ��
�㲻��ʳָ�󶯡��������ƾ��ң���Լ��������������ߺ�������������
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"zoulang1",
            "south" : __DIR__"tianpindian",
	    "west"  : __DIR__"center",
            "east"  : __DIR__"eroad2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -140);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
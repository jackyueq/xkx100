inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ�������ٲ������ɽ���������ٲ����΢���
�Կ���ɽ���Ĵ������������һ���ܴ����Ȼ��Ѩ������
�г����ź�Ũ�����ζ������������һ���ڶ���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "out" : __DIR__"pubu",
            "east" : __DIR__"shdong2",
        ]));
	set("coor/x", -6200);
	set("coor/y", -1150);
	set("coor/z", 100);
	setup();
        replace_program(ROOM);
}
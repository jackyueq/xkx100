// houshan.c ��ɽ
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
�����Ѿ���������������������ɽ�ĺ�ɽ���������ﻨ�㣬
�������£�ɽ��Ҳƽ���ö��ˡ�
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "west" : __DIR__"jingxiushi",
                "northeast" : __DIR__"xiaolu1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2720);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
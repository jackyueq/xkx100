// xiaolu11.c ��ɽС·
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��ɽС·");
        set("long", @LONG
�����Ǻ�ɽ�ϵ�С·������С·�������˹������޳����ģ�
Ҳ��ֻ����ǰ�Ĳ�ҩ�˲ȶ��ˣ��ֳ�����һ��С·�����ߵ����
�������·�ˡ�
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "east"  : __FILE__,
                "west"  : __DIR__"xiaolu10",
                "north" : __FILE__,
                "south" : __FILE__,
        ]));
        set("no_clean_up", 0);

	set("coor/x", -2660);
	set("coor/y", 140);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}

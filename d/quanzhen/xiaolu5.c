// xiaolu5.c ��ɽС·
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
                "east" : __DIR__"xiaolu9",
                "west" : __FILE__,
                "north" : __DIR__"xiaolu6",
                "south" : __DIR__"xiaolu3",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2690);
	set("coor/y", 140);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
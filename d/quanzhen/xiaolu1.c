// xiaolu1.c ��ɽС·
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��ɽС·");
        set("long", @LONG
�����Ǻ�ɽ�ϵ�С·������С·�������˹������޳����ģ�
Ҳ��ֻ����ǰ�Ĳ�ҩ�˲ȶ��ˣ��ֳ�����һ��С·����
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "northeast" : __DIR__"xiaolu2",
                "southwest" : __DIR__"houshan",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2710);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
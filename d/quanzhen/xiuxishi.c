// xiuxishi.c ��Ϣ��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�ܴ�ķ��䣬���߷ǳ��谵������û��ʲô��Ķ�����
ֻ���м����һ����ʰ����������Ĵ󴲣����ϵı���Ҳ�����
������࣬���ž�������˯����
LONG
        );

        set("exits", ([
                "west" : __DIR__"wuchang2",
                "northwest" : __DIR__"wuchang1",
                "south" : __DIR__"shantang",
        ]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("no_beg",1);
        set("no_fight",1);
        set("no_steal",1);

	set("coor/x", -2740);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
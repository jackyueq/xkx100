// lianwu.c ���䷿

inherit ROOM;

void create()
{
        set("short", "���䷿");
        set("long", @LONG
��������ػ�����䷿�����Ϲ���һЩ��Ƥ����Ƥ����Ҷ��Ƥ����
����ש���Ѿ�����ú������ˡ�ǽ������һЩ������������ػ������
��ϥ������
LONG );
        set("exits", ([
                "east" : __DIR__"dating",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 6
        ]));
	set("coor/x", -213);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
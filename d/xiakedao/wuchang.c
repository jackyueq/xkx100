// ROOM: /xiakedao/wuchang.c

inherit ROOM;
void create()
{
        set("short", "�䳡");
        set("long", @LONG
����һ������ʯ���������װ�¼����ˣ����Է���ʮ�˰����
��������ɢ�ķ���������ӣ��м�һ��������ɺ�ɫ�ĵ�̺����ʿ��
������������书��
LONG );
        set("exits", ([
                "west" : __DIR__"shibi",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 4,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -3070);
	set("coor/y", -25000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
inherit ROOM;

void create()
{
        set("short", "���ĸ�");
        set("long",@LONG
����������ɮǰȥ��Ժ����֮ǰ���ľ����ĵط�������ֻ�е������
�������ţ�����֮��������ȷȻ�Ǹ��徲֮����
LONG
        );
        set("exits", ([
		"south": __DIR__"doushuai",
                "north" : __DIR__"wuwujing",
	]));
	set("objects",([
                __DIR__"npc/xiaoshami" : 2,
        ]));
	set("sleep_room", 1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57070);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
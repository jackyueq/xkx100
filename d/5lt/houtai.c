// Room: /d/5lt/houtai.c

inherit ROOM;

void create()
{
	set("short", "��̨");
	set("long", @LONG
�������ݲ����ĺ�̨����Ա�ǵ��˿ն���������Ъ�������α�����
�ڵĹ����Ｗ������Ҫǩ���ĸ���Ӱ�ԡ�
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"southwest" : __DIR__"yanboting",
	]));
        set("objects", ([
		__DIR__"npc/niu": 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 35);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

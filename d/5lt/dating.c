// Room: /d/5lt/dating.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ͷ����̨�Ĵ�������������ܴ���������������ô
�󣬵ذ��ǹ⻬�Ĵ���ʯ�������浥�š��ſ�����һ�������������
�𱣻�����̨�İ�ȫ�Լ�һЩ������ӭ�������������Ϸ��и����ң���
��д�� 5LTTV�������֣��Եø������Ŀ��������һ��С�ţ�ͨ�����
̨�����ŷ������ġ�
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"up"     : __DIR__"mishuchu",
		"out"    : __DIR__"mubanlu",
		"east"   : __DIR__"fbzhongxin",
	]));
        set("objects", ([
		__DIR__"npc/ahda": 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

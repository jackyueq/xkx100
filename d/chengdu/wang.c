// Room: /d/chengdu/wang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������Ĵ��ţ����������������ʯʨ�ӣ��߸ߵ�̨�ף���
�������ţ������Ǳ��ţ�����������ʿ��������������ԣ��ſ��Եú�
��������ͨ�����ǲ������ġ�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east" : __DIR__"nanjie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


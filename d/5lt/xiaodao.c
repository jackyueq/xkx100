// Room: /d/5lt/xiaodao.c

inherit ROOM;

void create()
{
	set("short", "���С��");
	set("long", @LONG
�������ӿ����ݵ����С����·���Զ������˴��������������ȴ�
ֲ���ǰ�߾͵�����̨�ˡ�
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"north"     : __DIR__"mubanlu",
		"southeast" : __DIR__"wroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -185);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/yueyang/xianglushan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��¯ɽ");
	set("long", @LONG
��¯ɽ��λ�ڶ�ͥ���еľ�ɽ���棬��ԲԼ��Ķ��ɽ���®�Σ�ɽ
�Ϲ�ľ������������Ρ������ͱ����������Ϻ�ˮ���˸���ǰ��ײ����
��ʯ������һ��㲨�����Ե�ˮ�����ͺ�����������ϵ��һ����ɫ����
������ʱ¶��ˮ�棬��ʱ��û���������ͬһ������Ƕ�ڲ���׳����
��ͥ���ϣ������˰��ﶴͥ���;�ɽ������Ѥ�����˵�ɫ�ʣ�������ζ
���أ���Ȥ��Ȼ��
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"longwangmiao",
		"south"     : __DIR__"xiangchunting",
		"northdown" : __DIR__"yangeng2",
	]));
	set("coor/x", -1800);
	set("coor/y", 2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

// Room: /d/yanping/guandao2.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����������������ٵ��ϡ�����������ɽ���࣬��ˮ���䣬ɽ����
�������ˣ��ٵ���Ⱥ��������죬ɽ������ʱ���м�����������𣬲�
�������㷡�
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"guandao1",
		"northwest" : __DIR__"milin",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1700);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

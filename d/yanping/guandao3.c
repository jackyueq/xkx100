// Room: /d/yanping/guandao3.c
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
		"north"     : __DIR__"mazhan",
		"southeast" : __DIR__"milin",
		"southwest" : __DIR__"liyuding",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1550);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

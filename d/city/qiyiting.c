// Room: qiyiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������������������Ǹ�С��԰���̲����𣬳�֦ί�أ���
���ķ������죬�����ﶼ��ʧ�ˡ����н������ˣ�Ҳ����Ϣ�����ġ�ż
�������������������ﲻˬ���������裬��������˼��˳�ȥ��
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("exits", ([
		"west"       : __DIR__"weiqishi",
		"east"       : __DIR__"xiangqishi",
		"northwest"  : __DIR__"haizhanqi",
		"northeast"  : __DIR__"feixingqi",
		"south"      : __DIR__"zoulang2",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

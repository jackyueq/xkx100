// Room: /d/5lt/haitan.c

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "��̲");
	set("long", @LONG
��׵�ɳ̲���峺�ĺ�ˮ����ˬ�ĺ��硢���ĵ����⡢������涵�
Ҭ�֣�ÿ�춼�кܶ����������������Ĵ���Ȼ��⡣
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"west"   : __DIR__"yuchang",
		"south"  : __DIR__"xiaolu",
	]));
	set("coor/x", -195);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
}

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");

	if (arg != "chao" && arg != "tide")
		return notify_fail("��Ҫ����������\n");

	if (me->query_dex() < 59)
		return notify_fail("����ͼ���������ȴ�ܾ����������ġ�\n");

	if (me->query_skill("dodge") < 80)
		return notify_fail("����ͼ���������ȴ�����Լ����Ṧ��Ϊ��û�дﵽ��ô�ߵľ��硣\n");
	message_vision("$N����һԾ�������˺����У�\n", me);
	me->move(__DIR__"tide");
	return 1;
}
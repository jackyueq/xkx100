// Room: /d/nanshaolin/hguangc1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����Ǻ��㳡���ɴ���ʯ��ƴ�ɵĵ������м�����͹��̤�ۣ���
����ǰ�и���ʩչ�ڹ���������ӡ�ǡ���λִ��ɮ������Ľ�����ɨ��
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"      : __DIR__ "hguangc2",
		"north"     : __DIR__ "hguangc4",
		"southwest" : __DIR__ "huaishu5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
}

int init()
{
	add_action("do_ta","ta");
	add_action("do_ta","cai");
}

int do_ta(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("leg", 1), exp = me->query("combat_exp");
	if ( !living(me) || arg != "sign" ) return 0;
	if ((int)me->query_skill("leg", 1) > 31)
		return notify_fail("��̤��ӡ�Ѿ��޷��������Ļ����ȷ��ˣ�\n");
	if ( (int)me->query("jing")<30)
	{
		me->receive_damage("jing", 10);
		write("��̫���ˣ��Ѿ�û����������̤��ӡ�ˣ�\n");
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		me->receive_damage("jing", random(35));
		message_vision("$N���ڲ�̤�����ϵĽ�ӡ��\n", me);
		write("����ò�̤��ӡ����Ļ����ȷ������ٽ���\n");
		me->improve_skill("leg", me->query("int"));
	}
	return 1;
}


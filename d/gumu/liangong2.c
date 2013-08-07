// Room: /d/gumu/liangong2.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIR"������"NOR);
	set("long", @LONG
һ��ʯ�ң���״�������أ���(southwall)խ��(northwall)����
Ϊ���Σ���(eastwall)�߰�Բ����(westwall)��ȴ�������͡��Ҷ�ʯ��
��(top) ������㻨�Ʒ��ţ������������̳ɣ������ǳ�����޹���
�˴�����Ĺ�������������⹦��
LONG	);
	set("exits", ([
		"south" : __DIR__"mudao17",		
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_xiulian", "xiulian");
	add_action("do_tui", "tui");
	add_action("do_tui", "push");
}

int do_xiulian(string arg)
{
	mapping fam;
	object me = this_player();
	int c_exp, c_skill;

	if ( !arg ) 
		return notify_fail("��Ҫ����������������\n");
	c_exp=me->query("combat_exp");
	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if (me->query("jing") < 20)
		return notify_fail("�㾫�����ܼ��У�ȥ����ЪϢ�ɡ�\n");
	if ((int)me->query_skill("literate", 1) < 30)
		return notify_fail("��Ѿ���ֲ�ʶһ��������ɶ��\n");
	if (arg == "top")
	{
		if ((int)me->query_skill("sword", 1) < 20)
			return notify_fail("���������̫��޷���ϰȫ�潣����\n"); 
		if (me->query_skill("quanzhen-jian", 1) >= 1)
			return notify_fail("���Ѿ�ѧ��ȫ�潣�����Լ��ú����ɡ�\n");	 
		write("�������Ҷ���ͼ�ƣ����д�Ħȫ�潣���ľ���֮����\n");
		me->receive_damage("jing", 5);
		me->improve_skill("quanzhen-jian", 2);
		return 1;
	}
	if (arg == "southwall")
	{
		write("��������������ʯ�ڣ���һ���������������ֱ�һ�����顣\n");
		c_skill=(int)me->query_skill("strike", 1);
		if (c_skill > 50)
			return notify_fail("�������ۻ룬���������������ˡ�\n");
		me->receive_damage("jing", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("strike", random(me->query("int")));
		return 1;
	}
	if (arg == "northwall")
	{
		write("���ȭֱ�����ڣ�ʯ���Ľ�����Ҳ���Լ����;�����������\n");
		c_skill=(int)me->query_skill("unarmed", 1);
		if (c_skill > 50)
			return notify_fail("��ȭ���Ѹ����ޱȣ�ȴ����������\n");
		me->receive_damage("jing",5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("unarmed", random(me->query("int")));
		return 1;
	}
	if (arg == "eastwall")
	{
		write("���ƶ���ʯ��̤�Ž��������Ĵ�Ħ���Ͻ������衣\n");
		c_skill=(int)me->query_skill("sword", 1);
		if (c_skill > 50)
			return notify_fail("���ʯ��������������ȫȻ���գ������ٷ����ˡ�\n");
		me->receive_damage("jing", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("sword", random(me->query("int")));
		return 1;
	}
	if (arg == "westwall")
	{
		write("��������ָ���������ʯ�ڣ�ϸ�Ĳ����������շ����ơ�\n");
		c_skill=(int)me->query_skill("throwing", 1);
		if (c_skill > 50)
			return notify_fail("�㰵���շ����ģ��ٲ�������ڴˡ�\n");
		me->receive_damage("jing", 5 + random(15));
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("throwing", random(me->query("int")));
		return 1;
	}
	return notify_fail("���޷�����������������\n");
}

int do_tui(string arg)
{
	mapping fam; 
	object me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg == "eastwall")
	{
		if(!(fam=me->query("family")) || fam["family_name"] != "��Ĺ��")
			return notify_fail("�㲻�ǹ�Ĺ���ˣ����ܽ����Ĺ���ң�\n");
		message_vision(YEL "$N���ֵ���Բ�Ļ������˼��£�һ���ʯ�����ƿ����ֳ�һ�ȶ��š�\n"NOR, me);
		set("exits/enter", __DIR__"liangong3");
		me->receive_damage("qi", 30);
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

void close(object room)
{
	message("vision", HIY"��ʯ�����˻���ԭλ���ֵ�ס����ڡ�\n"NOR, room);
	room->delete("exits/enter");
}

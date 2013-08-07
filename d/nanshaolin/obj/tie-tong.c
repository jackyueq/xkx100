// Obj: /d/nanshaolin/obj/tie-tong.c 
// Last Modified by winder on May. 29 2001

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����Ͱ", ({"tie tong", "tong"}));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","һ�Դ���Ͱ����֮Ѱ��ˮͰ�����������ֻ࣬���ж��ٶ���ء�\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 10);
		set("shaolin", 1);
		set("no_drop", 1);
	}
	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"drunk_supply": 10,
	]));
}

void init()
{
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
	add_action("do_pour", "pour");
	add_action("do_pour", "dao");
}

int do_fill(string arg)
{
	object me = this_player();
	if (!arg || !id(arg)) return 0;
	if (base_name(environment(me)) != "/d/nanshaolin/fxjing")
	{
		write("ֻ����ɽ����ľ����ܹ�ˮ��\n");
		return 1;
	}
	message_vision("$N��$nװ����ˮ��\n", me, this_object());
	set("liquid/remaining", query("max_liquid"));
	return 1;
}

int do_pour(string arg)
{
	object me = this_player();
	if (!arg || arg != "gang") return 0;
	if (base_name(environment(me)) != "/d/nanshaolin/houdian")
	{
		write("Ҫ��������ˮ�����㵹ˮ��\n");
		return 1;
	}
	if (!query("liquid/remaining"))
	{
		message_vision("$N������ֻ����Ͱ���Ŵ�ˮ�ױȻ��š�\n", me);
		return 1;
	}
	if (query("liquid/remaining") < query("max_liquid"))
	{
		message_vision("$N������ֻûװ��ˮ����Ͱ���Ŵ�ˮ�ױȻ��š�\n", me);
		return 1;
	}
	message_vision("$N����ˮ�����ˮ���С�\n", me, this_object());
	me->receive_damage("qi", 100);
	if(me->query_skill("yiwei-dujiang", 1) < 150)
	{
		me->improve_skill("yiwei-dujiang", 2*(me->query("dex")));
	}
	delete("liquid/remaining");
	if (me->add("carry_count", -1) < 1)
	{
		me->delete("carry_count");
		message_vision("$N���������������Ͱ�����˸�������\n", me);
		if (present("liao kao", me)) destruct(present("liao kao", me));
		destruct(this_object());
	}
	return 1;
}


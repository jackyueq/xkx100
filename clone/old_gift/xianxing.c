// Last Modified by winder on Apr. 25 2001
// xianxing.c ����ը��

#include <ansi.h>

inherit ITEM;

int filter_user(object ob);

void create()
{
	set_name(HIR "����ը��" NOR, ({ "visible bomb", "bomb" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��˵���ǿ�������ԭ�α�¶��ը����\n");
		set("value", 1);
		set("no_sell", 1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_bomb", "bomb");
}

int do_bomb()
{
	object me;
	object *ob;
	string msg;

	me = this_player();
	message_vision(HIM "$N��ȵ�����ͳͳ�������Σ���˵�հ����е�ը��"
		       "һ�ӣ��������䡱��һ����\n" NOR, me);

	ob = filter_array(all_inventory(environment(me)), (: filter_user :));
	switch (sizeof(ob))
	{
	case 0:
		msg = HIG "һ���������ʲô�仯Ҳû�У�ֻ��$N�ǺǵĲ�סɵЦ��\n" NOR;
		break;
	case 1:
		if (ob[0] == me)
			msg = HIC "һ���������ֻ��$N�Լ���ը�û�"
			       "�����̣�ԭ�α�¶��\n" NOR;
		else
			msg = HIC "һ���������" HIG + ob[0]->name() +
			       HIC "��ը�û������̣����ڵ��ϡ��໡�ֱ�С�\n" NOR;
		break;
	default:
		msg = HIC "һ���������һ���˱�ը�û������̣�ԭ�α�"
		       "¶��\n" NOR;
		break;
	}

	message_vision(msg, me);
	destruct(this_object());
	return 1;
}

int filter_user(object ob)
{
	if (! userp(ob))
		return 0;

	if (ob->query("env/invisible"))
	{
		ob->delete("env/invisible");
		CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + ob->query("name") +
				      "��ը�������Ρ�");
		return 1;
	}

	if (! undefinedp(ob->query_temp("apply/name")))
	{
		object mask;
		string msg;

		msg = "��˵" + ob->query("name") + "�ٰ�" + ob->name() +
		      "��ը����ԭ�Σ��������¶���С��";
		ob->delete_temp("apply/name");
		ob->delete_temp("apply/id");
		ob->delete_temp("apply/short");
		ob->delete_temp("apply/long");
		if (objectp(mask = present("mian ju", ob)))
		{
			msg += "����" + mask->name() + HIM "�����ջ��ˡ�";
			destruct(mask);
		} else
			msg += "��";
		CHANNEL_D->do_channel(this_object(), "rumor", msg);
		return 1;
	}

	return 0;
}

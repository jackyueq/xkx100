// zeng.c

#include <ansi.h>;
inherit NPC;
inherit F_DEALER;

int working(object me);
int halt_working(object me);
string ask_job();
void create()
{
	set_name("����", ({ "zeng rou", "zeng", "rou" }));
	set("shen_type", 1);

	set("gender", "Ů��");
	set("age", 16);
	set("per", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("str", 25);
	set("long",
"����Τ��ү��֪���ڼ�����С檣������￪�������̣���Щ��֪��
�������·�������˵�Ƕ���Τ��ү�ӹ���Ū�����Ľ�Ʒ������ô˵��
�����������\n");
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	map_skill("unarmed", "changquan");
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		CLOTH_DIR+"cloth/belt",
		CLOTH_DIR+"cloth/boots",
		CLOTH_DIR+"cloth/bu-shoes",
		CLOTH_DIR+"cloth/cloth",
		CLOTH_DIR+"cloth/color-dress",
		CLOTH_DIR+"cloth/feature",
		CLOTH_DIR+"cloth/fu-cloth",
		CLOTH_DIR+"cloth/gui-dress",
		CLOTH_DIR+"cloth/hat",
		CLOTH_DIR+"cloth/jade-belt",
		CLOTH_DIR+"cloth/liu-dress",
		CLOTH_DIR+"cloth/marry-dress",
		CLOTH_DIR+"cloth/mini-dress",
		CLOTH_DIR+"cloth/moon-dress",
		CLOTH_DIR+"cloth/pink-dress",
		CLOTH_DIR+"cloth/qi-dress",
		CLOTH_DIR+"cloth/red-dress",
		CLOTH_DIR+"cloth/scarf",
		CLOTH_DIR+"cloth/sha-dress",
		CLOTH_DIR+"cloth/shoes",
		CLOTH_DIR+"cloth/xian-cloth",
		CLOTH_DIR+"cloth/xiu-cloth",
		CLOTH_DIR+"cloth/xiu-scarf",
		CLOTH_DIR+"cloth/yan-dress",
		CLOTH_DIR+"cloth/zi-dress",
	}));
	set("inquiry", ([
//		"����" : (: ask_job :),
//		"job"  : (: ask_job :),
	]));

	setup();
	carry_object(CLOTH_DIR+"cloth/feature")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sew", "sew");
}

string ask_job()
{
	object me = this_player();
	object *obs;

	if (me->query_temp("job/sew")) return "���������·���Ū����ô��";
	if (me->query("gender") != "Ů��") return "��Ů���ӼҵĻ���Ҳ���ɣ�";
	if (me->query("combat_exp") < 50)
		return "������������ɻ��һ����е㲻���ġ�";
//	if (me->query("combat_exp") > 15000)
//		return "�������ã������ǿ���ʲô�õ��Լ�ѡ���ɣ������ɻ�Ҳ̫ί���ˣ�";
	if (me->query("qi") < 30) return "����ɫ��ô�������Ъ����ɡ�";
	if (me->query("jing") < 30)
		return "�㾫��ͷ���а�������ҵ�������̤�ˣ�";
	if (me->query_int() < 20)
		return "����...����ô���ֱ��ŵģ�Ҳ�����·���";
	if (! interactive(me)) return "...";
	obs = filter_array(all_inventory(environment()),
		(: interactive($1) &&
		$1 != $(me) &&
		$1->query_temp("job/sew") &&
		query_ip_number($1) == query_ip_number($(me)) :));
	if (sizeof(obs) > 0)
		return "�����Ѿ���" + obs[0]->name() + "�ڰ��������������ˡ�";

	me->set_temp("job/sew", 1);
	return "�ã���Ͱ�������÷�(sew)��С��ɣ������������������";
}

int do_sew(string arg)
{
	object me = this_player();
	if (me->is_busy())
		return notify_fail("����æ���أ����ż���\n");
	if (! me->query_temp("job/sew"))
	{
		message_vision("$N͵͵������һ�����룬$nһ����߸��������ҷ��£���ʲô����ģ�\n", me, this_object());
		return 1;
	}

	me->set_temp("job/step", 1);
	me->start_busy(bind((: call_other, __FILE__, "working" :), me), bind((: call_other, __FILE__, "halt_working" :), me));
//	me->start_call_out((:call_other,__FILE__,"working", me, 1:), 5);
	tell_object(me, "�㿪ʼ���ҡ�\n");
	return 1;
}

int working(object me)
{
	string msg;
	int finish;
	int b;

	if (! me->query_temp("job/step")) me->set_temp("job/step", 1);
	if (! living(me))
	{
		me->delete_temp("job/sew");
		me->delete_temp("job/step");
		return 0;
	}

	finish = 0;
	me->receive_damage("jing", 1);
	me->receive_damage("qi", 2);
	switch (me->query_temp("job/step"))
	{
		case 1:
			msg = "$N����һ�����룬�������ߡ�";
			break;
		case 2:
			msg = "$Nչ�����ϣ��������ӱȻ��˰��졣";
			break;
		case 3:
			msg = "$N��������������ӣ����¼�����ӡ��";
			break;
		case 4:
		case 6:
			msg = "$Nר����־��һ��һ�ߵķ��ҡ�";
			break;
		case 5:
			msg = "$N��ü���˿����ӣ�������˼��";
		case 7:
			msg ="$N�ᶯ����ϸָ���������´����·���ģ�������ĳ����ˡ�";
			break;
		default:
			msg = "$N���·���ã�������ϣ����õݸ�$n��";
			finish = 1;
			break;
	}
	msg += "\n";

	if (finish)
	{
		object ob;
		msg += "$n����$N��������·�����ͷ���������е���˼��\n";
		me->delete_temp("job/sew");
		me->delete_temp("job/step");

		b = 5 + random(5);
		me->add("combat_exp", b);
		me->improve_potential((b + 2) / 3);

		ob = new("/clone/money/coin");
		ob->set_amount(60);
		ob->move(me, 1);
	}

	msg = replace_string(msg, "$N", "��");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

	if (finish)
	{
		if (b > 0)
		{
			tell_object(me, HIC "\n������" + chinese_number(b) + "�㾭���" + chinese_number((b + 2) / 3) + "��Ǳ�ܡ�\n\n" NOR);
		}
		return 0;
	}

	me->add_temp("job/step", 1);
	return 1;
}

int halt_working(object me)
{
	message_vision("$N�����е�����һ�ӣ��ֹ�������û���������ﲻ���ˣ���\n", me);
	me->delete_temp("job/sew");
	me->delete_temp("job/step");
	return 1;
}


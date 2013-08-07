// zhu.c ����

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("�����", ({ "feng congwu", "feng" }));
	set("long",
"�������ǵ�����ѧ�ߣ���ͨ������\n");
	set("gender", "����");
	set("age", 65);
	set("no_get", 1);
	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	setup();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0;
	ob->add_temp("mark/��", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();
	if (!(int)who->query_temp("mark/��"))
		who->set_temp("mark/��", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("�����ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
		who->add_temp("mark/��", ob->value() / 50);
		return 1;
	}
}


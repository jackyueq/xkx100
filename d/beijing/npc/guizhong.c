// /beijing/npc/guizhong.c
// Last modified by winder 2003.10.10

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("����", ({ "gui zhong", "gui" }));
	set("long", "һ���첡����ס�Ŀ��ԣ�����ȴ������С����һ\n"
		"�㣬�����ǹ�����֮�ӹ��ӣ���С�������ಡ��\n");
	set("gender", "����");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 10);
	
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);

	set("combat_exp", 500000);
	set("score", 20000);

	set_skill("cuff", 120);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("strike", 120);
	set_skill("zixia-shengong", 80);
	set_skill("poyu-quan", 120);
	set_skill("hunyuan-zhang", 120);
	set_skill("feiyan-huixiang",80);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");

	set("chat_chance", 20);
	set("chat_msg", ({
		CYN "��������ؿ����˼�����\n" NOR,
		CYN "���ӿ����˼�����һ�����ǵ�ͨ�졣\n" NOR,
	}) );

	create_family("��ɽ��", 32, "����");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/beijing/obj/hupi")->wear();
}

void kill_ob (object ob)
{
	object me = this_object();
	object where = environment (me);
	object guard = present ("gui erniang", where);

	set_temp("my_killer",ob);
	::kill_ob(ob);
	if (guard && !guard->is_fighting())
	{
		message_vision (HIR "$N" HIR "��ŭ����������̫"
				"������������飡\n" NOR, guard);
		guard->kill_ob(ob);
	}
}

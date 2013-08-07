// guanfuzi.c �ذ��� 

#include <ansi.h>;

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int ask_weiwang();

void create()
{
	set_name("�ذ���", ({ "guan anji", "guan" }));
	set("nickname", "�ط���");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 35);
	set("long", "ֻ���������ĺ���Ʈ����ǰ��ģ���������ϡ�����˳ƹط��ӡ�\n");

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1200);
	set("max_jing", 1200);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 35);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("claw", 70);
	set_skill("hand", 70);
	set_skill("literate", 50);
	set_skill("yunlong-shengong", 80);
	set_skill("yunlong-shenfa", 80);
	set_skill("yunlong-shou", 80);
	set_skill("yunlong-zhua", 80);
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-shou");
	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_msg", ({
		"�ذ�����Ȼ˵�����õ�����˭���������ֲ�����˵����\n",
		"�ذ�����Ȼ˵�������ҵ�Ƣ������ã���ҿ�ҪС���ˡ�\n",
	}));
	set("inquiry", ([
		"�½���" : "����ܶ����ɲ����װ���\n",
		"��ػ�" : "ֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" : "ֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
		"���帴��" : "ȥ���׳��͹ײĵ���ϸ���ưɣ�\n",
		"����" : (: ask_weiwang :),
		"��������" : (: ask_weiwang :),
	]) );
	set("party/party_name", HIR"��ػ�"NOR);
	set("party/rank", HIG"��ľ��"NOR"����");
	create_family("������", 2, "����");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int recognize_apprentice(object ob)
{
	if (ob->query("weiwang")<50)
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
		command("tell "+ob->query("id")+" ������ػ�����Ҳ��̡�\n"); 
		return 0;
	}
	return 1;
}

void init()
{
	add_action("do_join","join");
}

void die()
{
	message_vision("\n$N��ŭ��������ҿ����ӣ��ֵ��ǻ����ұ���ģ���˵�굹�����ˡ�\n", this_object());
	::die();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
	say( "\n�ذ���˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ����������\n");
	say("�ذ�����˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}
#include "tiandihui.h";

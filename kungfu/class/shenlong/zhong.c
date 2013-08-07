// bailong shi ����ʹ
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit NPC;

string ask_ob(string);
void apply_gift(object, int);

void create()
{
	set_name("��־��", ({ "zhong zhiling","bailong shi", "shi","zhong" }));
	set("long", "����󺺣�һ����֪�ǹض��ˡ�\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 32);
	set("int", 26);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 50000);
	set("shen", -20000);

	set_skill("force", 100);
	set_skill("dulong-dafa", 100);
	set_skill("dodge", 80);
	set_skill("yixingbu", 80);
	set_skill("strike", 100);
	set_skill("huagu-mianzhang", 80);
	set_skill("parry", 90);
	set_skill("hook", 150);
	set_skill("ruyi-hook", 100);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("hook", "ruyi-hook");

	prepare_skill("strike", "huagu-mianzhang");
	set("inquiry", ([
		"�鰲ͨ" : "������������˵����",
		"�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
		"����"   : "û��û�صġ�",
		"������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
		"������" : "һ�������벻���������̵�(join shenlongjiao).\n",
		"���"   : "һ�������벻���������̵�(join shenlongjiao).\n",
		"����"   : "����Ƣ�����ã�Ҫ�������Ĳźá�\n",
		"�ں�"   : "���겻�ϣ������ɸ����������룡������ʥ��\n",
	]));
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIW"������"NOR"����ʹ");
	set("party/level", 2);
	create_family("������", 2, "����");

	setup();
	carry_object(WEAPON_DIR"hook")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();	
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_join","join");
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
		if (obj = present("usedgao", ob))          
		{
			set("combat_exp",100000);
			set("qi",100);
			set("jing",100);
		}
	}
	return;
}

void attempt_apprentice(object ob)
{
	command("say ���߿������ң�");
	return;
}
#include "/kungfu/class/shenlong/shenlong.h"; 

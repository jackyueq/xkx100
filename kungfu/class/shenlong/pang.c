// pang.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("��ͷ��", ({ "pang toutuo", "pang" ,"toutuo"}));
	set("nickname",HIR "�ɶ�������" NOR);
	set("long", "��ͷ�������ߣ��ݵó��棬����Ƥ����ͷ��˫Ŀ���ݣ�\n"
		"������罩ʬһ�㳤�����磬ͷ��һ��ͭ����ס�˳�����\n"
		"���ϴ�һ�����ۣ�������������ǹ����¼��ϡ�\n");
	set("gender","����");
	set("gender", "����");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi", 2000);
	set("qi", 2000);
	set("max_jing", 1000);
	set("jing", 1000);
	set("combat_exp", 400000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("leg", 80);
	set_skill("strike", 80);
	set_skill("staff", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("yixingbu", 120);
	set_skill("jueming-leg", 120);
	set_skill("huagu-mianzhang", 120);
	set_skill("dulong-dafa", 70);
	set_skill("shenlong-staff", 120);

	map_skill("staff", "shenlong-staff");
	map_skill("force", "dulong-dafa");
	map_skill("leg", "jueming-leg");
	map_skill("strike", "huagu-mianzhang");
	map_skill("staff", "shenlong-staff");
	map_skill("parry", "jueming-leg");
	map_skill("dodge", "yixingbu");
	prepare_skill("leg", "jueming-leg");
	prepare_skill("strike", "huagu-mianzhang");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.hua" :),
		(: perform_action, "strike.baigu" :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang3" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIC"�󻤷�"NOR);
	set("party/level", 2);
	create_family("������", 2, "����");

	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
	set("inquiry", ([
		"�鰲ͨ" : "������������˵����",
		"�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
		"����"   : "û��û�صġ�",
		"������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
		"������" : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"���"   : "һ�������벻���������̵�(join shenlongjiao)��\n",
		"����"   : "����Ƣ�����ã�Ҫ�������Ĳźá�\n",
		"�ں�"   : "���겻�ϣ������ɸ����������룡������ʥ��\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
	add_money("silver", 10);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "������" NOR )
	{
		command("say �㲻�Ǳ��̽��ڣ�������������");
		return;
	}
	if ((int)ob->query("shen") > -0 )
	{
		command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/shenlong/shenlong.h"; 

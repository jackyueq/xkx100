// a-xiu.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>

inherit NPC;

string ask_staff();
void create()
{
	set_name("����",({"a xiu","xiu"}));
	set("gender", "Ů��");
	set("age", 16);
	set("long", 
	       "����������������Ů���귽ʮ���꣬��������������ɰ���\n��ֱ���Ǵ�ѩɽ�����ǵ�С������\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("count",1);
	set("con", 30);
	set("per", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("qi", 800);
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("inquiry", ([
		"ʯ����"   : "���ȥ�����͵�����֪����������ô���ˣ�",
		"������"   : "ֻ���Ҳ�����ô����������ô����ô������",
		"ʯ����"   : "�Һ�������---��ȥ��������ɱ�˰ɡ�",
		"����"   : "�����ҵ�ѽ��",
		"������"   : "������үүѽ��",
		"������" : (: ask_staff :),
	]) );
	set("combat_exp", 50000);
	set("shen_type", 0);
	set("chat_chance", 5);
	set("chat_msg", ({
		"����������ƽ����̶ˮ��˵����̶����֣����������ʲô������\n",
		"���忴��Զɽ�����ư��ƣ�̾������Ҫʲôʱ��Ŵ����͵�������\n",
		"�����Ȼ��򭲻�죬����������ʲô����֮�¡�\n",
	}) );
	set("score", 2000);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 40);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 40);

	set_skill("xueshan-sword", 60);
	set_skill("bingxue-xinfa", 60);
	set_skill("snow-strike", 60);
	set_skill("snowstep", 60);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("������", 7, "����");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}
string ask_staff()
{
	object ob;
	object me;
	me = this_player();

	if(query("count") < 1)
		return "��λ" +RANK_D->query_respect(me)+"�����Ǳ�Ǹ���������Ѿ����˰��Ҹ����̴�ȥ�ˡ�";
	if(me->query("combat_exp")<200000)
		return "���书��δ���ң������Ұѽ����Ƚ����㣿";
	add("count", -1);
	ob=new(WEAPON_DIR"treasure/jinwu-staff");
	if ( ob->violate_unique() )
	{
		destruct( ob );
		return "���书��δ���ң������Ұѽ����Ƚ����㣿";
	}
	else
	{
		ob->move(this_player());
		return "��λ" +RANK_D->query_respect(me)+"������Ұ���ѽ����ȴ��������̣����Ƕ�л�ˡ�";
	}
}

void attempt_apprentice(object ob)
{
	command("say ���ǲ���ͽ�ģ����������ʦ���Ǻ��ˡ�");
}


// Room: /d/xingxiu/npc/piaoran.c
// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit NPC;
string ask_job();
void create()
{
	set_name("ƮȻ��", ({ "piaoran zi", "piaoran", "zi" }) );
	set("gender", "����" );
	set("nickname", "�����������");
	set("age", 28);
	set("long", "��������а���书��ǿ�������������Ҹ�Ů��
��������ʿ��ɱ�������������ӻ������޺󣬾���û���������ɽ����\n");
	set("env/wimpy", 40);
	set("str", 28);
	set("dex", 10);
	set("con", 25);
	set("int", 22);
	set("shen", -10000);

	set_skill("force", 100);
	set_skill("huagong-dafa", 105);
	set_skill("strike", 100);
	set_skill("chousui-zhang", 105);
	set_skill("poison", 100);
	set_skill("parry", 100);
	set_skill("staff", 100);
	set_skill("tianshan-zhang", 100);
	set_skill("literate", 50);
	map_skill("force", "huagong-dafa");
	map_skill("strike", "chousui-zhang");
	map_skill("parry", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");

	set("max_qi", 1100);
	set("max_jing", 900);
	set("neili", 1500);
	set("eff_jingli", 1100);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 600000);
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
	}));
	
	create_family("������", 2, "����");
	set("inquiry", ([
		"������" : "������룬�Ͱ���Ϊʦ��",
		"���޺�" : "ȥ���޺���ʲô������Ϊʦ�͹���ѧ���ˡ�",
		"������" : "����������е���û��ûС�ġ��Ժ�����ɣ�",
		"����"   : (: ask_job :),
		"��"     : (: ask_job :),
		"poison" : (: ask_job :),
	]));	
	setup();
	carry_object("clone/cloth/dao-cloth")->wear();
	add_money("silver", 10);
}

string ask_job()
{
	object me;
	mapping fam;
	int poison, exp;
	me = this_player();
	fam = (mapping)me->query("family");
	poison = me->query_skill("poison", 1);
	exp=me->query("combat_exp",1); 
 
	if(!fam) return "�����ӹ�һ��ȥ��";
	if(fam["family_name"] != "������" && !me->query_temp("ding_flatter"))
		return "�����ӹ�һ��ȥ��";
	if(poison < 120) return "������������ѧ���˻����Ķ��������ɡ�";
	if(poison >= 200) return "������������ָ�ʬ���������ûʲô���˰ɣ�";
	if(me->query_skill("huagong-dafa", 1) < 100 )
		return "��Ļ����󷨻������죬�������Σ�յģ�";
	if(me->query_condition("wait_xx_task"))
		return "������ʦ�ֵ���������˰ɣ������ͺúõ��š�";  
	if(me->query_condition("xx_task") || me->query_condition("xx_task2"))
		return "�㻹��Ϊ����ʦ�ֵ��������أ������������������ɡ�";   
	if(interactive(me) && me->query_temp("xx_job"))
		return "����ô�������﷢����";

	me->set_temp("promotion_target",1 );
	message_vision("\n$N����$n�ٺ�һЦ�����������ǰɣ���ȥ�����Լ��Ҿ����õ�ʬ��������\n", this_object(), me);
	return "��ס���ɲ���ɱ��С��������������ۣ�\n";    
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	mapping fam;
	fam = (mapping)me->query("family");

	if (fam["family_name"] != "������")
	{
		command("say ����������"+RANK_D->query_rude(me)+"�������ô����޽��أ�");
		kill_ob(me); 
	}
}
void kicking(object who)
{
	if(!who || environment(who) != environment())  return;
	who->move("/d/xingxiu/cave");
	message("vision","ֻ����������һ����������"+who->query("name")+"�Ӻڰ���ֱ�ɳ�����ˤ�˸��Ľų��죡\n", environment(who), who);
	who->receive_wound("jing", 200);
	who->receive_wound("qi", 250);
	who->start_busy(5);
}
int accept_object(object who, object ob,object me)
{
	object obj;
	if(!objectp(obj = present("shi guan", environment()))) return 0;
	if(obj->query_temp("liandu"))
	{
		command("say ʯ���������أ���ȵȰɡ�");
		return 0;
	}
	if(ob->query("id") != "corpse")
	{
		command("say ����ʲô��������");
		return 0;
	}
	if(userp(ob))
	{
		command("stare " + who->query("id"));
		command("say ������������ƭ�ң����ҹ���ȥ��");
		message_vision("\n˵��$N˫��ǰ�ƣ�һ���ھ��������ͽ�$n������⣡\n\n", this_object(), who);
		kicking(who);
		return 0;
	}
	if(!who->query_temp("promotion_target"))
	{
		command("say �������þ�ʬ����Ҹ�ʲô��");
		return 0;
	}       
	if ( ob->query("kill_by") != who)
	{
		command("say �ٺ٣�����ʬ����ʬ������Ҫ�Լ�����ɱ�ģ�������һ�߰ɡ�");
		return 0;
	}
	if ( (ob->query("victim_user") &&
		ob->query("victim_exp") < who->query("combat_exp")/3) ||
		(!ob->query("victim_user") &&
		ob->query("victim_exp") < who->query("combat_exp")))
	{
		command("say �ٺ٣������˵��̫����ʬ��û�ã�������һ�߰ɡ�");
		return 0;
	}
	if (interactive(who) && (who->query_condition("xx_task") ||
		who->query_condition("xx_task2")))
	{
		command("pat "+ who->query("id"));
		command("say �㻹��Ϊ����ʦ�ֵ��������أ������������������ɡ�");
		return 0; 
	}
	call_out("put_in", 4, ob, this_object(), who, obj);
	return 1;
}

int put_in(object corpse, object ob, object me, object obj)
{
	object *inv;
	int i;
	if(!objectp(present(obj, environment(ob))))
	{
		command("say �ף�ʯ����ô�����ˣ�");
		command("drop corpse");
		return 1;
	}
	if(!objectp(present(me, environment(ob))))
	{
		command("say Ү���Ǽһ���ô�����ˣ�");
		command("drop corpse");
		return 1;
	}

	inv = all_inventory(corpse);
	i = sizeof(inv);
	while(i--) destruct(inv[i]);
	corpse->move(obj); 
	if(corpse->query("victim_user")) obj->set_temp("liandu", 2);
	else obj->set_temp("liandu", 1);
	obj->set_temp("liandu_target", me->query("id"));
	obj->set("arg", ob->query_temp("dest"));
	command("nod "+me->query("id"));
	command("say �ðɣ�����������ϰ(liandu)һ�¶����ɡ�");
}

// fusigui.c ��˼��

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
string ask_join();
int ask_me();
void create()
{
	set_name("��˼��", ({ "fu sigui", "fu" }));
	set("title",  "������" );
	set("long", "���Ǵ�����Ĵ���֮һ��\n");
	set("gender", "����");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("env/wimpy", 60);	
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("score", 105000);

        set_skill("force", 55);
        set_skill("dodge", 55);
        set_skill("parry", 50);
        set_skill("cuff", 55);
        set_skill("sword", 50);
        set_skill("staff", 50);
	set_skill("kurong-changong", 50);
        set_skill("tiannan-step", 70);
        set_skill("jinyu-quan", 70);
        set_skill("duanjia-sword", 75);
	set_skill("literate", 40);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),				
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	set("inquiry", ([
		"ָ���书" : (: ask_me :),
		"��ٸ�" : (: ask_join :),
		"join" : (: ask_join :),
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 10);

	create_family("����μ�",19,"����");
}
string ask_join()
{
	object ob = this_player();
	string *applied_id;

	if (ob->query("combat_exp")<10000)
		return ("����书̫�ʲôҲ�����˵ġ�\n");

	if (ob->query_temp("dali_join"))
		return RANK_D->query_respect(ob) + 
		"�����Ѿ��Ǳ���������ˣ��ιʻ�Ҫ��������Ц��";
	ob->set_temp("dali_join",1);
	if( pointerp(applied_id=ob->query_temp("apply/id")) && sizeof(applied_id) )
		ob->set_temp("apply/short", ({HIY"����������������"NOR+" "+ob->name()+"("+applied_id[0]+")"}));
	else
	       ob->set_temp("apply/short", ({HIY"����������������"NOR+" "+ob->name()+"("+ob->query("id")+")"}));       
	command("look "+ob->query("id"));
	return "�ã�������λ�ֵܿ���Ϊ�����������ˡ�";
}
#include "/kungfu/class/dali/weishi.h"; 

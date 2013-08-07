// zhuwanli.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
int ask_for_toushen();
void create()
{
	set_name("������", ({ "zhu wanli", "zhu" }));
	set("title",  "���������" );
	set("long", "���Ǵ�����Ĵ���֮һ�������£�����Ӣ�����ˡ��ֳ�һ�����ˡ�\n");
	set("gender", "����");
	set("age", 33);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	set("no_get",1);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 100000);

	set("inquiry",([
		"Ͷ��"    : (: ask_for_toushen :),
		"toushen" : (: ask_for_toushen :),
		"ָ���书" : (: ask_me :),
	]));

        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("sword", 50);
        set_skill("staff", 50);
	set_skill("kurong-changong", 50);
        set_skill("tiannan-step", 70);
        set_skill("jinyu-quan", 70);
        set_skill("duanjia-sword", 75);
	set_skill("literate", 30);

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

	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object(__DIR__"obj/diaogan")->wield();
	add_money("silver", 10);

	create_family("����μ�",19,"����");
}
int ask_for_toushen()
{
	object me;

	me = this_player();

	if( (string)me->query("class") == "eunach")
	{
		command("say ���������Ǹ��ﲻ�չ�����\n");
		return 1;
	}
	if( (string)me->query("class") == "bonze")
	{
		say( "������˵������λ" + RANK_D->query_respect(me)
			+ "���������Ļ������мң�\n");
		return 1;
	}
	if( (int)me->query_str() < 20)
	{
		say( "������˵������λ" + RANK_D->query_respect(me)
			+ "��ô��������ô���ڸ����ֵ��\n");
		return 1;
	}
	say( "������˵������λ" + RANK_D->query_respect(me)
		+ "��ί�������ڸ������ðɡ�\n");
	me->set("guard","����������ū");
	return 1;
}
#include "/kungfu/class/dali/weishi.h"; 

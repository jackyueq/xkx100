// xiaoweri.c Уξ
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL "Уξ" NOR, ({ "xiao wei", "jiang" }));
	set("title","�����ر�");
	set("age", 31);
	set("gender", "����");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	set("chat_chance", 30);
	set("chat_msg", ({
		"������ô����������Ǹ�Уξ��������������\n",
		"�����ݻ�����ô�����ˣ�ȴ�ö�ط�ûȥ��������\n",
		"������������͸���ˡ�����\n",
		"Уξ�ȵ����󵨵��񣬾���ɱ�٣�Ī�������췴���ɣ�\n",
		"Уξ�ȵ����㻹���ӳ����ι��粻�ɣ����ǹԹ�Ͷ���ɣ�\n",
	}));
	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
	carry_object(__DIR__"obj/jitui")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting()
{
	object me = this_player();
	if( me->query_condition("killer") )
	{
		message_vision( "Уξ����$N���һ������ɱ�˷Ż�ĵ��񣬿�������ɣ������� \n", me );
		kill_ob(me);
	}
}

int accept_fight(object me)
{
	object *all;
	int i;
	if ( random(5) == 0 )
	{
		command("say ��ү�ҽ�������ã����ң�����������\n");
		return 0;
	}
	command("say �ҿ�������ǻ�ò��ͷ���,"+RANK_D->query_rude(me)+",ȥ���ɣ�\n");
	me->apply_condition("killer", 360);
	all = all_inventory(environment(me));
	for ( i = 0; i < sizeof( all ); i ++ )
	{
        if ( all[ i ]->id("shi bing") || all[ i ]->id("xiao wei")
		|| all[ i ]->id("wu jiang") )
		all[ i ] -> kill_ob(me);
	}
	return 1;
}

int refuse_killing(object me)
{
    object *all;
    int i;

    me->apply_condition("killer", 360);
    all = all_inventory(environment(me));
    for ( i = 0; i < sizeof( all ); i ++ )
    {
        if ( all[i]->id("shi bing") || all[i]->id("xiao wei")
            || all[i]->id("wu jiang") )
            all[i] -> kill_ob(me);
    }
    return 1;
}


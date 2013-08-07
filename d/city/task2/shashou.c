// shashou.c ɱ��
#include <ansi.h>;
#include "init.h";
inherit NPC;

void create()
{
	mapping name;
	switch (random(3))
	{
		case 0:
			name = NAME_D->man_name();
			set("gender", "����");
			break;
		case 1:
			name = NAME_D->woman_name();
			set("gender", "Ů��");
			break;
		default:
			name = NAME_D->jap_name();
			set("gender", "����");
			break;
	}
	set_name(name["name"],({name["id"]}));
	set("title","һƷ��ɱ��");
	set("long",
		"����һλ������µ��ˣ�����ͨ����ȫûʲô������\n");
	set("age", 20 + random(25) );
	set("attitude", "heroism");
	set("str", 20 + random(11));	// ����
	set("per", 20 + random(11));	// ��ò
	set("int", 20 + random(11));	// ����
	set("con", 20 + random(11));	// ����
        set("dex", 100 + random(11)); 	// ��
	set("kar", 20 + random(11));	// ��Ե
	set("shen", -10);
	set("demogorgon",1);
	set("no_suck",1);
        set( "max_qi", 1200 + random(400) );
	set( "max_jing", 300 + random(300) );
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 60);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge", 40);
	setup();
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "parry.ren" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 20);
}


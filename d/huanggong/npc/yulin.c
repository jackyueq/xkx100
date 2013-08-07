// yulin.c

#include <ansi.h>
inherit NPC;
inherit F_SKILL;

void create()
{
	set_name(HIC"���־�"NOR, ({"yulin jun", "jun"}));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("shaolin-shenfa", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("damo-jian", 50);
	map_skill("sword", "damo-jian");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/d/city/obj/gangjian")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
	if(interactive(ob =this_player())&&(int)ob->query_class("officer"))
	{
	message_vision("���־������㶼���ڵ���˵: ū�Ÿ������밲��\n"+
"       ����Ҫ��ʥ�뵽�����鷿�����,С��ְ������,�����չ��ˡ�\n",this_player())
;
}
}


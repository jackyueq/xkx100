// shuchi.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("����",({"shu chi","shu","chi"}));
	set("gender","����");
	set("long","��ľ��Ĵ���ӣ�������������������թ��\n");
	set("combat_exp",150000);
	set("age",39);
	set("qi",1200);
	set("max_qi",1200);
	set("food",250);
	set("water",250);
	set("neili",900);
	set("max_neili",900);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("spear", 60);
	set("chat_chance",5);
	set("chat_msg",({
		"����ٺ���Ц���������̨�Ǹ���������[��]��λ�ó������ҵġ�\n",
		"����������ϵĽ��ף���Ѫɫ�����Ѿ�һ��������\n",
	}));
	setup();
	add_money("silver",30);
	carry_object("/clone/armor/yinjia")->wear();
	carry_object("/clone/weapon/spear/jinqiang")->wield();
}


// muhuali.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("ľ����",({"mu huali","mu","huali"}));
	set("gender","����");
	set("nickname","�ɹ��Ľ�");
	set("long","��ľ�������Ľ�֮һ����ԭ�ϵ����ߣ��󺹵ľ�ʦ��\n");
	set("combat_exp", 200000);
	set("age",45);
	set("qi",2000);
	set("max_qi",2000);
	set("food",250);
	set("water",250);
	set("neili", 1500);
	set("max_neili", 1500);
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("unarmed", 80);
	set_skill("spear", 80);

	setup();
	add_money("silver",20);
	carry_object("/clone/armor/tongjia")->wear();
	carry_object("/clone/weapon/spear/tieqiang")->wield();
}

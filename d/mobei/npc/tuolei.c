// tuolei.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("����",({"tuo lei","tuo","lei"}));
	set("gender","����");
	set("long","��ľ����Ķ��ӣ��������ֵ������вŻ��ġ�
��Ȼ��û�еõ���λ�����ɸ��ԴΣ���Ԫһ�����󺹾�Ϊ�������\n");
	set("combat_exp", 50000);
	set("age",15);
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
	setup();
	add_money("silver",30);
	carry_object("/clone/armor/yinjia")->wear();
	carry_object("/clone/weapon/spear/jinqiang")->wield();
}


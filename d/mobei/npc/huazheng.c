// huazheng.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("���ݹ���",({"huazheng gongzhu","huazheng","gongzhu"}));
	set("gender","Ů��");
	set("long","��ľ���СŮ����������δ�����ӡ�\n");
	set("combat_exp", 20000);
	set("age",16);
	set("qi",900);
	set("max_qi",900);
	set("food",250);
	set("water",250);
	set("neili",500);
	set("max_neili",500);
	set_skill("dodge",30);
	set_skill("force",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_skill("whip",30);

	setup();
	add_money("silver",10);
	carry_object("/clone/cloth/luoyi")->wear();
	carry_object("/clone/weapon/whip/whip")->wield();
}


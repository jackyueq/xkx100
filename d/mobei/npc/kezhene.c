// kezhene.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("�����",({"ke zhene","ke","zhene"}));
	set("gender","����");
	set("long","�����߹�֮�ף���ϧ����ǰ���ڷ�˫ɷ�������ӣ�\n");
	set("combat_exp", 800000);
	set("nickname","��������");
	set("age",54);
	set("qi",1800);
	set("max_qi",1800);
	set("food",250);
	set("water",250);
	set("neili",1800);
	set("max_neili",1800);
	set("force_factor",20);

	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("staff", 100);

	setup();
	add_money("silver",80);
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/staff/tiezhang")->wield();
}

// supu.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "su pu", "su", "pu"}));
	set("gender", "����");
	set("age", 19);
	set("long", 
"һ����˶�Ĺ��������꣬ͷ����³�˵ĺ��ӡ�\n");
	set("combat_exp", 20000);
	set("shen_type", 1);
	set("jiali", 10);

	set_skill("force", 20);
	set_skill("blade", 20);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);

	set("inquiry", ([
		"������" : "��үү˵�Ǹ�����С�����Ѿ����������ˡ�\n",
		"��³��" : "�����ҵ���\n",
		"����"   : "�����������Ա�ô����\n",
	]) );

	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 10);

	setup();
	carry_object("/d/xingxiu/obj/wandao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}


//Edited by fandog, 01/31/2000

inherit NPC;

void create ()
{
	set_name("����˼", ({"ling tuisi","ling"}));
	set("title", "����֪��");
	set("long", "
һλ���꺺�ӣ����λ���һ������֮ɫ�������Ǿ���֪�����ˣ��˳ơ��躲�֡���\n");
	set("gender", "����");
	set("age", 45);
	set("combat_exp", 1000000);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("yanfly", 100);
	set_skill("tangshi-jian", 100);
	map_skill("dodge", "yanfly");
	map_skill("parry", "tangshi-jian");
	map_skill("sword", "tangshi-jian");
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}



//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("��ͨ", ({"lv tong","lv"}));
	set("long", "���Ǹ�������ף����ο���Ĵֺ����ӡ�\n");
	set("gender", "����");
	set("title", "̫��ɽկ��");
	set("age", 38);
	set("combat_exp", 50000);
	set("str", 23);
	set("int", 22);
	set("con", 21);
	set("dex", 18);
  
	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("yanfly", 50);
	set_skill("changquan", 50);
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "yanfly");
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}



//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("�߷�����", ({"lang zhong","doctor"}));
	set("long", "����һ��ҡ�Ż������ؽ���ҩ���߷����С�\n");
	set("gender", "����");
	set("age", 32);
	set("combat_exp", 50000);
	set("str", 19);
	set("int", 25);
	set("con", 18);
	set("dex", 25);
	set("per", 18);
	set("kar", 18);
  
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/jiangling/obj/hucheng");
}


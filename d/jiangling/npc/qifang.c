//Edited by fandog, 02/13/2000
inherit NPC;

void create ()
{
	set_name("�ݷ�", ({"qi fang","qi"}));
	set("long", "һλ��ɫ�������ٸ���ԲԲ��������һ˫���ۺ�����ģ����ϲ�ʩ֬�ۣ���ɫ��Ϊ�㲡�\n");
	set("gender", "Ů��");
	set("age", 20);
	set("combat_exp", 100000);
	set("str", 20);
	set("int", 28);
	set("dex", 23);
	set("con", 26);
	set("per", 26);
	set("kar", 26);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("yanfly", 60);
	set_skill("tangshi-jian", 60);
	map_skill("dodge", "yanfly");
	map_skill("parry", "tangshi-jian");
	map_skill("sword", "tangshi-jian");
  
	setup();
	carry_object("/clone/cloth/female-cloth")->wear();
}



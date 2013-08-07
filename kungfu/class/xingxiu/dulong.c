// dulong.c ������

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("������", ({ "dulong zi", "dulong", "zi" }));
	set("nickname", "�������ĵ���");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 15);
	set("combat_exp", 100000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("huagong-dafa", 4);
	set_skill("dodge", 60);
	set_skill("zhaixinggong", 50);
	set_skill("claw", 50);
	set_skill("sanyin-wugongzhao", 20);
	set_skill("strike", 50);
	set_skill("chousui-zhang", 20);
	set_skill("parry", 50);
	set_skill("staff", 80);
  	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"������" : "��ϧ���ɲ�׼����ͽ, ������ɰ���Ϊʦ��",
		"�"   : "�ʰ��ϰɡ�",
		"����"   : "Сʦ����������ϲ��, ��ȥ�����ɡ�",
		"����"   : "Ҫ��������, �����ס��Сʦ�á�",
		"����"   : "��öവ������, ��������г�ͷ֮�ա�\n",
		"������" : "����������е���? û��ûС�ġ��Ժ������! ",
		"���޺�" : "�����ں�æ, �ұ��˴���ȥ�ɡ�",
		"����ľ��" : "�ҿ�û���, �����������㡣",
		"ɽ��"   : "����, ����ʯ�ƿ����Ϳ��Խ�ȥ����? ",
	]) );
	create_family("������", 2, "����");
	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
  	carry_object("/d/xingxiu/obj/changpao")->wear();
}

void attempt_apprentice(object ob)
{
	command("say �ҲŲ�����ͽ�ء�");
}

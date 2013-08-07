// danqing-sheng.c 
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("������", ({ "danqing sheng", "sheng" }));
	set("long",
		"������÷ׯ��λׯ�����е��ĵĵ�������\n"
		"��һ���ɸɾ�������ɫ���ۡ�\n"
		"����������Ѯ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
	set("gender", "����");
	set("age", 41);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("env/wimpy", 40);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("shen", 15000);
	set("score", 60000);

	set_skill("painting", 100);         // ��ī����
	set_skill("literate", 100);         // ����ʶ��
	set_skill("force", 80);             // �����ڹ�
	set_skill("dodge", 80);             // ��������
	set_skill("parry", 80);             // �����м�
	set_skill("sword", 80);             // ��������
	set_skill("piaoyibu", 120);          // Ʈ�ݲ���
	set_skill("pomopima-jian", 120);    // ��ī���齣
	set_skill("kuihua-xinfa", 80);	    // �����ķ�

	map_skill("force", "kuihua-xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "pomopima-jian");
	map_skill("sword", "pomopima-jian");

	set("inquiry", ([
		"����"     : (: ask_me :),
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	])); 
	set("item_count", 1);
	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIG"÷ׯ��ׯ��"NOR);
	create_family("��ľ��", 9, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"�������"NOR)
	{
		command("say ��ֻ����̵��ӣ������Ĵ��ó������ȥ��\n");
		return;
	}
	if ((int)ob->query("shen") < 0)
	{
		command("say �����䲻��ʲô�������ɣ�����÷ׯ����ͽҲ��Ϊ�ϸ�");
		command("say ��Ʒ�з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ��Ϸ���������ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��ľ��")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";
	if (query("item_count") < 1)
		return "�������ˣ�÷�����Ʋ��ڴ˴���";
	add("item_count", -1);
	ob = new("/d/meizhuang/npc/obj/lingpai");
	ob->move(this_player());
	return "�ðɣ����÷�����ƾͽ����㱣���ˡ�";
}


// zi.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�ڰ���", ({ "heibai zi", "zi" }));
	set("long",
		"������÷ׯ��λׯ�����еڶ��ĺڰ��ӡ�\n"
		"��һ���ɸɾ����ĺ�ɫ���ۡ���ɫȴ���ס�\n"
		"����������Ѯ����ĸߴ�˫���������, һ����֪��һλ�ڼҵĸ��֡�\n");
	set("gender", "����");
	set("age", 52);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("env/wimpy", 40);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 80);
	set("combat_exp", 1000000);
	set("shen", 15000);
	set("score", 60000);

	set_skill("goplaying", 100);        // ������̸
	set_skill("literate", 100);         // ����ʶ��
	set_skill("force", 120);            // �����ڹ�
	set_skill("finger", 120);           // ����ָ��
	set_skill("dodge", 120);            // ��������
	set_skill("parry", 120);            // �����м�
	set_skill("piaoyibu", 180);         // Ʈ�ݲ���
	set_skill("xuantian-zhi", 180);	    // ��������ָ
	set_skill("kuihua-xinfa", 120);	    // �����ķ�

	map_skill("force", "kuihua-xinfa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "xuantian-zhi");
	prepare_skill("finger", "xuantian-zhi");

	set("inquiry", ([
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	]));

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIB"÷ׯ��ׯ��"NOR);
	create_family("��ľ��", 9, "����");

	setup();
	carry_object("/d/meizhuang/npc/obj/heiyi")->wear();
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"�������"NOR)
	{
		command("say ��ֻ����̵��ӣ������Ĵ��ó������ȥ��\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa", 1) < 90)
	{
		command("say ��ѧ�ҽ̹������ڹ��ϣ�" + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö��µ㹦��");
		return;
	}
	command("say �ðɣ����¾��������ˡ�");
	command("recruit " + ob->query("id"));
}


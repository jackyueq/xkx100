// lvzhuweng.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "luzhu weng", "weng" }));
        set("long",
"�������������ͣ�ͷ��ϡϡ��������޶���ͷ�������ִ�ţ�����ȴʮ�����塣\n");
        set("gender", "����");
        set("age", 62);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("env/wimpy", 40);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 1400);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 80);
        set("combat_exp", 1200000);
        set("shen", 15000);
        set("score", 60000);

	set_skill("literate", 100);         // ����ʶ��
	set_skill("force", 100);            // �����ڹ�
	set_skill("dodge", 100);            // ��������
	set_skill("parry", 100);            // �����м�
	set_skill("dagger", 100);           // �����̷�
        set_skill("shigu-bifa", 100);       // ʯ�Ĵ�Ѩ�ʷ�
	set_skill("piaoyibu", 100);         // Ʈ�ݲ���
	set_skill("kuihua-xinfa", 100);	    // �����ķ�

	map_skill("force", "kuihua-xinfa");
	map_skill("dagger", "shigu-bifa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "shigu-bifa");

	set("inquiry", ([
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	]));

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", "����");
        create_family("��ľ��", 9, "����");

        setup();
        carry_object("/d/meizhuang/npc/obj/panguan-bi")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wield();
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"�������"NOR)
	{
		command("say ��ֻ����̵��ӣ������Ĵ��ó������ȥ��\n");
		return;
	}
        if ((int)ob->query_skill("kuihua-xinfa",1) < 50)
	{
                command("say Ҫ�ٳ߸�ͷ����һ����" + RANK_D->query_respect(ob) + "�Ƿ����ҽ̵��ڹ��϶��µ㹦��");
                return;
        }
        command("say �ðɣ��Ϸ���������ˡ�");
        command("recruit " + ob->query("id"));
}


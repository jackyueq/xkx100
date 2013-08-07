// ren.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("������", ({ "ren woxing", "ren","woxing" }));
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ���㣬
������ߣ�һͷ�ڷ���������һϮ������\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("no_get", 1);
	set("bihua", 10);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
 	set("jiali", 400);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);         // ����ʶ��
	set_skill("force", 200);            // �����ڹ�
	set_skill("finger", 200);           // ����ָ��
	set_skill("unarmed", 200);          // ����ȭ��
	set_skill("dodge", 200);            // ��������
	set_skill("parry", 200);            // �����м�
	set_skill("dagger", 200);           // �����̷�
	set_skill("sword", 200);            // ��������
        set_skill("shigu-bifa", 200);       // ʯ�Ĵ�Ѩ�ʷ�
	set_skill("piaoyibu", 200);         // Ʈ�ݲ���
	set_skill("wuyun-jian", 200);       // �������ҽ�
	set_skill("xuantian-zhi", 200);     // ��������ָ
	set_skill("kuihua-xinfa", 200);     // �����ķ�
	set_skill("xixing-dafa", 200);      // �����ķ�
	set_skill("changquan", 200);        // ̫�泤ȭ
	set_skill("damo-jian", 200);        // ��Ħ����
	set_skill("taiji-jian", 200);       // ̫������
	set_skill("huifeng-jian", 200);     // �ط������
	set_skill("taishan-sword", 200);    // ̩ɽ����
	set_skill("hengshan-jian", 200);    // ��ɽ����
	set_skill("hengshan-sword", 200);   // ��ɽ����
	set_skill("huashan-sword", 200);    // ��ɽ����
	set_skill("songshan-sword", 200);   // ��ɽ����

	map_skill("force", "xixing-dafa");
	map_skill("sword", "wuyun-jian");
	map_skill("dagger", "shigu-bifa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "damo-jian");
	prepare_skill("finger", "xuantian-zhi");

        set("inquiry", ([
                "�Ƚ�" :  (: ask_bijian :),
                "����" :  (: ask_bijian :),
                "��ľ��" : "Ҫ�ú�ľ��Ϸ����ȿ�����Ľ�����\n",
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	]) );

	set("party/party_name", HIB"�������"NOR);
	set("party/rank", HIW"���ߴ�����"NOR);
	create_family("��ľ��", 7, "����");
 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_bijian()
{
	object weapon, obj, me = this_player(), ob = this_object();
	int i;

        if (!objectp(weapon = ob->query_temp("weapon")))
	{
		weapon = new("/clone/weapon/changjian");
		weapon -> move(ob);
		command("wield sword");
	}
	if(query("bihua") < 0)
	{
		message_vision("$N����˵���������������Ұݼ�����ǰ�����������ָ�̡���\n$n��Ц�����������Ĺ���ô���ҽ������ң�����\n", me, ob );
		return 1;
	}
	add("bihua", -1);
	message_vision("$N����˵���������������Ұݼ�����ǰ�����������ָ�̡���\n$nЦ���������ÿ������������Ҽ�į���ɶ�л��������\n", me, ob );
	message_vision("$N���������ҡ���\n$n���˵�ͷ��˵��������ֻ��������Ľ�����������Ĺ��У���˵����Ҳδ����ʤ�����㡣��\n\n", me, ob);
        command("xkx ���ӽ������µ�һ�����ұȽ�������!");
	command("enable sword damo-jian");
	say(HIR"�����д��һ���������ֽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵��������һ�С���\n");
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"�����д��һ�������䵱��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"�����д��һ���������ҽ�������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword songshan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword taishan-sword");
	say(HIR"�����д��һ������̩ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword huashan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword hengshan-sword");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵�����������С���\n");
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"�����д��һ��������ɽ��������"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("������̾�˿�����˵����������û�����С���\n");
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	me -> set_temp("renwoxing/bijian", 1);
	say("������˵��������λ" + RANK_D->query_respect(me)+"�����Ҿ�����һ���ľ��ɡ���\n");
	return 1;
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"�������"NOR)
	{
		command("say ��ֻ����̵��ӣ������Ĵ��ó������ȥ��\n");
		return;
	}
	if (ob->query("betrayer"))
	{
		command("say ���ǲ�����ͽ�ġ�");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa",1) < 150)
	{
		command("say ���ǲ�������ͽ�ġ�");
		command("say ���ҽ̵��ڹ��ϣ�" + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�ö��µ㹦��");
		return;
	}
	if (ob->query_temp("renwoxing/bijian"))
	{
		ob->delete_temp("renwoxing/bijian");
		if ( ob->query("kar") == this_object()->query("kar"))
		{
			command("say �ðɣ���Ȼ�������ͶԵ���Ϸ���������ˡ�");
                        command("xkx �Ϸ��յ������ͽ����������С����ı�Ӧ����!");
			command("recruit " + ob->query("id"));
		}
		else
		{
			message_vision(
"$N�������ŵ�����������������һ��Ӣ���˵ã��ο��������֮�к͸�
��ͬ�ֻࣿ�����������Ϊͽ�������Գ���ɽ���Ե�����������������
��������һ���Ƚ�������ĺ���ʤ�ţ������������ֻ��������գ����
��ض�ô����������ү�ӳ��ú��Σ������µ���Ů���ף���Ҫɱ��һ��
��ɱ��һ�������˸�����ү��Υ������ʹ��֮������\n", ob);
			command("say �ߣ��ҲŲ�����ĵ��ء�");
		}
	}
	else
		command("say �ðɣ����ȿ�����Ľ����ɡ�");
}


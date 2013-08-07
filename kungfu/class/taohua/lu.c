// lu.c
#include <command.h>
#include <ansi.h>
inherit NPC;                                                                    
inherit F_MASTER;                                                               
string ask_yao();
void create()
{
        set_name( "½�˷�" ,({ "lu chengfeng", "lu" }));
        set("gender", "����");
        set("age", 52);
        set("long",
            "½�˷��ǻ�ҩʦ�ĵ��ĸ�ͽ�ܡ�\n"
            "�����޽���΢���׷�������Ŀ��࣬˫������\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 28);
        set("con", 30);
        set("dex", 30);
        set("chat_chance", 1);
        set("max_qi",1500);
        set("max_jing",500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("shen_type",1);
        set("env/wimpy", 60);

        set("combat_exp", 300000);
        set_skill("force", 90);             // �����ڹ�
        set_skill("bibo-shengong", 80);     // �̲���
        set_skill("unarmed", 90);           // ����ȭ��
        set_skill("xuanfeng-leg", 130);      // ����ɨҶ��
        set_skill("strike", 90);            // �����Ʒ�
        set_skill("luoying-zhang", 130);     // ��Ӣ����
        set_skill("dodge", 70);             // ��������
        set_skill("anying-fuxiang", 100);    // ��Ӱ����
        set_skill("parry", 90);             // �����м�
        set_skill("sword", 90);             // ��������
        set_skill("luoying-shenjian", 130);  // ��Ӣ��
        set_skill("literate",90);           // ����ʶ��
        set_skill("qimen-wuxing",60);       // ��������

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "xuanfeng-leg");
        map_skill("strike" , "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-shenjian");
        map_skill("sword"  , "luoying-shenjian");
	prepare_skill("unarmed", "xuanfeng-leg");
	prepare_skill("strike", "luoying-zhang");

        set("inquiry", ([
           "�һ���":   "�������Ǳ��ɵ��ӣ����һ�����Ҫ���һ���",
           "��а":     "��ʦ�˳ƶ�а���Ǻǡ�",
           "����":     "ŷ���������ʦ���������ĸ��֣��˳��϶��",
           "�ϵ�":     "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
           "��ؤ":     "��ؤ���߹���ؤ��������������ݳ��⡣",
           "����":     "����ʦ���İ�Ů��",
           "��ҩʦ":   "��Ҫ�ݷü�ʦ��",
           "�޳���":   "���Ǽ�ʦ���䵤ҩ������������У�",
           "�Ż���¶��":  (: ask_yao :)
        ]) );
        set("jinbing", 10);
        set("yao_count", 1);

        create_family("�һ���", 2, "���� ����ׯׯ��");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query_dex() < 20)
        {
           command("say �����书���������ɽݡ�");
           command("say ��λ"+RANK_D->query_respect(ob)+"�����ǰ�������ׯһ���ˡ�");
           return;
        }
        if ((int)ob->query("shen") < 0)
        {
           command("say �����ڽ���������������"+ RANK_D->query_respect(ob)+"��ذɡ�");
           return;
        }
        if (ob->query("gender") == "����")
        {
           command("say ʦ�������᲻�в�Ů�Ķ����ˣ���λ"+RANK_D->query_respect(ob)+"�Ͽ���ɡ�");
           return;
        }
        if (ob->query("class") == "bonze")
        {
           command("say ʦ�����ɮ�ֵ��ˣ���λ"+RANK_D->query_respect(ob)+"������ذɡ�");
           return;
        }
        if (ob->query_skill("literate",1) <= 10)
        {
           command("say �һ���ֻ�ն����������ӣ���λ"+RANK_D->query_respect(ob)+"�Ƿ�ȥ������������");
           return;
        }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + "�������£���Ŭ�����顣");
        command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
        command("wield jian");
}
int accept_object(object who, object ob)
{
	int exp,pot,score;
	if (query("jinbing") < 0)
	{
                command("say " + RANK_D->query_respect(who) + "�Һ��ۣ����ͷ�������Ͱɡ�");
		return 0;
	}
	if (ob->query("userp") == 1)
	{
		message_vision("$N����$n˵���ҽ���ɱ�𹷣���ȴȥɱ��ң�ȥ�����㣡\n", this_object() , who);
		this_object()->kill_ob(who);
		return 1;
	}
	if (strsrch(ob->query("name"), "���տ���ͷ­") < 0 &&
	    strsrch(ob->query("name"), "���պ��ҵ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ŷ�����ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ŷ���˵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "��������ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����̵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�������˵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ɳͨ���ͷ­") < 0 &&
	    strsrch(ob->query("name"), "��ͨ����ͷ­") < 0 &&
	    strsrch(ob->query("name"), "����յ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����ҵ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����۵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "Ǯ�ཡ��ͷ­") < 0 &&
	    strsrch(ob->query("name"), "������ͷ­") < 0 &&
	    strsrch(ob->query("name"), "����µ�ͷ­") < 0) 
	{
                command("say ������Щ������ʲô�ã�\n");
		return 0;
	}
	else
	{
                command("say ��������һֱ��ɱ��Щ�𹷣�л������ˡ�");
	}
	exp = 20 + random(30);
        pot = 20 + random(10);
	score = 30 + random(20); 
	who->add("combat_exp", exp);
	who->add("potential",pot);
	who->add("score", score);		
	add("jinbing", -1);
	tell_object(who,HIW"������"+chinese_number(exp)+"��ʵս�����"+chinese_number(pot)+"��Ǳ�ܺ�"+chinese_number(score)+"�㽭��������\n"NOR);
	return 1;
}
string ask_yao()
{
	object ob, me = this_player();
	
	if (me->query("family/family_name")!="�һ���")
		return RANK_D->query_respect(me) + "�����ɵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("yao_count") < 1 || random(3) > 0)
		return "�������ˣ��Ż���¶���Сʦ���ˡ�";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/jiuhuawan");
	ob->move(me);
	return "�ðɣ�����Ż���¶����ȸ���ɡ�";
}

// hong.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
int try_to_learn_ds();

void create()
{
	set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "��ָ��ؤ");
	set("gender", "����");
	set("age", 75);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
	"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
	"���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
	"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
	}));
	set("inquiry", ([
		"������" : "����������������\n",
		"ؤ��" : "����������������\n",
	]));
	set("no_teach", ([
				"xianglong-zhang" : (: try_to_learn_ds :),
	]));
	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);
	
	set("combat_exp", 3000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 200);             // �����ڹ�
	set_skill("huntian-qigong", 200);    // ��������
	set_skill("unarmed", 200);           // ����ȭ��
	set_skill("dodge", 200);      	     // ��������
	set_skill("xiaoyaoyou", 300);        // ��ң��
	set_skill("parry", 200);             // �����м�
	set_skill("strike", 200);            // �����Ʒ�
	set_skill("xianglong-zhang", 300);   // ����ʮ����
	set_skill("hand", 200);              // �����ַ�
	set_skill("suohou-hand", 300);       // ����������
	set_skill("blade", 200);             // ��������
	set_skill("liuhe-blade", 300);       // �������ϵ�
	set_skill("staff", 200);             // �����ȷ�
	set_skill("fengmo-staff", 300);      // ��ħ�ȷ�
	set_skill("stick", 200);             // ��������
	set_skill("dagou-bang", 300);        // �򹷰���
	set_skill("begging", 100);           // �л�����
	set_skill("checking", 100);          // ����;˵
	set_skill("training", 100);         // Ԧ����
	set_skill("lianhua-zhang",100);      // ������
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "lianhua-zhang");
	map_skill("hand",  "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "dagou-bang");
	map_skill("stick", "dagou-bang");
	map_skill("staff", "fengmo-staff");
	prepare_skill("hand",  "suohou-hand");
	prepare_skill("strike", "lianhua-zhang");
  

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", HIR"����"NOR);
	set("party/level", 10);
	create_family("ؤ��", 17, "����");

	setup();
	
	carry_object(__DIR__"obj/lvyv_bang")->wield();
	carry_object(__DIR__"obj/jiaohuaji");
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
 	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_qiecuo","qiecuo");
}


void greeting(object me)
{
       
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "ؤ��")&&(!me->query_skill("huntian-qigong",1))&&(me->query("combat_exp")>500000))
        {
                command("say �㾹�ҷ��������ķ��������������ȥ�ɣ�");
                command("expell " + me->query("id"));
        }
        
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "ؤ��")
	{
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
		return;
	}
	if (ob->query_temp("jiahuoji")) command("recruit "+ob->query("id"));
	else
	command("say " + RANK_D->query_respect(ob) + "��������������ֻ��ϧ�Ͻл�����û������ͽ����");
	
}

int accept_object(object who, object ob)
{
        int lv;
        string by,hid;
        object hob;
        object me=this_object();
        if (ob->query("food_supply") <= 0)
        	return 0;
        if ((string)ob->query("id") != "jiaohua ji" && !ob->query("values"))
        {
        	"/cmds/std/say"->main(this_object(),"�Ͻл���" + (string)ob->query("name") + CYN+"ûʲô��Ȥ����");
        	return 0;
        }
        if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
        	command("say �Ͻл����ڱ��úܡ�");
        	return 0;
        }
        if((string)ob->query("id") == "jiaohua ji")
        {
        	command("say ����������������ԵĽл���ѽ��");
          command("eat ji");
          who->set_temp("jiahuoji",1);
          return 1;
        }
        lv = ob->query("values");
        by  = ob->query("make_by");
        if (lv < 100)
        {
                message_vision(CYN "$N" CYN "������" + ob->name() +
                               CYN "����ü�����ⶫ���㻹���Ը�����"
                               "�ɡ�\n" NOR, me);
                return 0;
        }

        if (lv < 120)
        {
                message_vision(CYN "$N" CYN "������" + ob->name() +
                               CYN "����ζ�������ɻ�����΢Ƿ��ô"
                               "������\n" NOR, me);
                return 0;
        }

        message_vision(HIW "$N" HIW "������$n" HIW "������" + ob->name() +
                       HIW "�����˼��ڣ�ֱ����ͷ���������ޡ�\n" NOR, me, who);

        if (! who->id(by))
        {

                command("say ��ϧ��֪����˭���ģ��пտɵø�������������");
                return 1;
        }

        if (who->query("gender") != "Ů��")
        {
                command("say �벻����һ������ү������Ҳ�����ѵã��ѵá�");
                return 1;
        }

        if (who->query("family/family_name") == query("family/family_name"))
        {
                command("say �����������������治���Ժ�Ϳ�����չ��ˡ�");
                return 1;
        }

        if (ob->query("id")!="yudiluomei")
        {
                "/cmds/std/say"->main(this_object(),"�Ͻл��ҳԱ���ϱ�������"+ob->query("name")+CYN+"Ҳ�����˼���ζ������������");
                return 1;
        }

        if (who->query("can_learn/hong/xiaoyaoyou") >= 1)
        {
                command("pat " + who->query("id"));
                command("say �ָ��Ͻл�������ˣ���л����л��");
                return 1;
        }
        command("stuff");
        command("say �Ͻл�ûɶֵǮ�ģ��ʹ���һ������Ϊ����ɡ�");

        tell_object(who, HIC "\n���߹�ͬ�⴫���㡸��ң��������\n" NOR);
        who->set("can_learn/hong/xiaoyaoyou", 1);

        if (lv >= 200)
        {
                message_vision(CYN "\n$N" CYN "��˼���ã��ֵ����벻"
                               "�����˻�Ѿͷ����Ȼ�����������������"
                               "ζ��\n" NOR, me, who);

                if (! stringp(hid = who->query("couple/couple_id")))
                {
                        command("say ȴ��֪��������ż���û�У���Ҫ"
                                "�Ͻл�������ܣ�");
                        return 1;
                }

                if (! objectp(hob = find_player(hid)))
                {
                        command("sigh");
                        command("say ��ϧ����λ���ڣ������ҵ��ǿ���"
                                "�������ֹ��򡣰��ˣ����ˡ�");
                        return 1;
                }

                if (hob->query("family/family_name") == query("family/family_name"))
                {
                        command("say " + hob->name(1) + "��Ȣ������"
                                "�������ţ�Ҳ�����ˡ�");
                        return 1;
                }
                command("say ʲôʱ�����Ҳ������λ������Ҳ�����㶫����");

                tell_object(hob, HIC "\n���߹�ͬ�⴫���㡸����ʮ���ơ���\n" NOR);
                hob->set("can_learn/hong/sub-xianglong-zhang", 1);
//                hob->improve_skill("martial-cognize", 1500000);
        }
        destruct(ob);
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if (! me->query("can_learn/hong/sub-xianglong-zhang")
           && ! me->query("can_learn/hong/xiaoyaoyou"))
        {
                command("say ����˭���������ģ�Ҫ��ɶ��");
                return notify_fail("");
        }

        if ((me->query("can_learn/hong/sub-xianglong-zhang")
           && skill != "xianglong-zhang"
           && skill != "strike")
           || (me->query("can_learn/hong/xiaoyaoyou")
           && skill != "xiaoyaoyou"
           && skill != "dodge"))
        {
                command("say �Ͻл�����ʲô��ѧʲô���㲻ѧ�����ˡ�");
                return notify_fail("");
        }

        if ((skill == "strike"
           && me->query_skill("strike", 1) > 179)
           || (skill == "dodge"
           && me->query_skill("dodge", 1) > 179))
        {
                command("say ����Ϊֹ����Ĺ���Ҳ�����ˣ�ʣ�µ��Լ�ȥ����");
                return notify_fail("");
        }
        return 1;
}

int try_to_learn_ds()
{
        object me;
        object sob;
        int i;
        int flag;
        string *sub_skills;

        me = this_player();

        if (me->query("family/family_name") == query("family/family_name")
           && me->query("party/level") < 9)
        {
                command("say ��Ҫѧ����ʮ���ƣ������������ﳤ����˵�ɣ�");
                return 1;
        }

        if (me->query("family/family_name") != query("family/family_name")
           && ! me->query("can_learn/hong/sub-xianglong-zhang"))
        {
                command("say �����������ģ�һ�ߴ���ȥ��");
                return 1;
        }

        if (me->query("shen") < 80000)
        {
                command("say ����������»����ò������ҿɲ����Ĵ��������");
                return 1;
        }

        sob = find_object(SKILL_D("xianglong-zhang"));

        if (! sob)
                sob = load_object(SKILL_D("xianglong-zhang"));

 //       if (! sob->valid_learn(me))
 //               return 0;

        if (me->query_skill("xianglong-zhang", 1))
        {
                command("say �㲻���Ѿ�����ô���Լ��ú����ɡ�");
                return 1;
        }
        
        if ((int)me->query("max_neili") < 3000)
        {
            command("say �������̫�������޷�������ʮ���ơ�");
            return 1;
        }
        if ((int)me->query("str") < 25)
        {
            command("say �����������������������������ʮ���ơ�");
            return 1;
        }
        if ((int)me->query("con") < 20)
        {
            command("say ����������������������������ʮ���ơ�");
            return 1;
        }
        if ((int)me->query_skill("strike", 1) < 180)
        {
            command("say ��Ļ����Ʒ���򲻹���������������ʮ���ơ�");
            return 1;
        }

        sub_skills = keys(sob->query_sub_skills());

        flag = 0;
        for (i = 0; i < sizeof(sub_skills); i++)
        {
                if (me->query_skill(sub_skills[i], 1) >= 10)
                        continue;

                me->set_skill(sub_skills[i], 10);

                if (! flag)
                {
                        flag = 1;
                        command("nod");
                        command("say �ҽ�ʮ��·�Ʒ��������㣬����ʱ"
                                "�գ������ڻ��ͨ��");
                }
                write(HIC "���" + to_chinese(sub_skills[i]) + "����"
                      "һЩ����\n" NOR);
        }

        if (! flag)
        {
                command("say ����˵�˴������ڻ��ͨ���������ֽ���");
                return 1;
        }

        me->set("can_learn/hong/sub-xianglong-zhang",1);
        command("say ���Ƚ���ʮ��·�Ʒ��ڻ��ͨ���϶�Ϊһ��˵�ɡ�");
        notify_fail("���Լ���ȥ�ú���ϰ�ɡ�\n");
        return 1;
}
// /kungfu/class/xueshan/fawang.c  ���ַ���
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
        set_name("���ַ���", ({ "jinlun fawang", "fawang", "fawang" }));
        set("long",@LONG
����ѩɽ�µĻ��̷�������ѩɽ�µĵ�λ�������������Ħ�ǡ�
��һ���Ϻ����ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "����" NOR);
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
        set("combat_exp", 1200000);
        set("score", 200000);

        set_skill("necromancy", 100);
        set_skill("force", 200);
        set_skill("longxiang", 200);
        set_skill("dodge", 150);
        set_skill("shenkong-xing", 210);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 300);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 150);
        set_skill("lamaism", 150);
        set_skill("literate", 80);
        set_skill("hammer", 200);
        set_skill("riyue-lun", 220);
        set_skill("dashou-yin",220);
        set_skill("hand",200);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "dashou-yin");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        map_skill("hand","dashou-yin");
	prepare_skill("hand", "dashou-yin");
	prepare_skill("unarmed", "yujiamu-quan");
        set("env/wimpy", 60);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "fenchang" :),
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
        }) );
        create_family("ѩɽ��", 2, "���̷���");
        set("class", "lama");

        setup();
        if (clonep())
        {
        	ob=new(WEAPON_DIR"treasure/jinlun");
        	if ( ob->violate_unique())
        	{
            destruct(ob);
            ob=new(WEAPON_DIR"hammer");
          }
          ob->move(this_object());
          ob->wield();
       	}
        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("gold",1);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("class") != "lama") {
                command("say �����ػƽ����ڵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }

        if ((string)ob->query("family/family_name") != "ѩɽ��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
                  }

        if ((int)ob->query_skill("lamaism", 1) < 80) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }

        command("smile");
        command("nod");
        command("say �������ѧϰ�𷨰ɣ�");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY"���"NOR);
}

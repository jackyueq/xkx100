// liu.c ������

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({"liu chuxuan", "liu"}));
        set("gender", "����");
        set("age", 38);
        set("class", "quanzhen");
        set("nickname",WHT"������"NOR);
        set("long",
                "������ȫ����ͽ�����������ˣ��������С����Ŀ����Գ�\n"
                "�����μ�����һ���������š�\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 30);

        set("title","ȫ������֮��");

//       set("env/wimpy", 60);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: exert_function, "powerup" :),
                (: exert_function, "recover" :),                
                (: perform_action, "strike.ju" :),                
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.sanqing" :),                
        }));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 500000);
        set("score", 300000);

        set_skill("array", 80);
        set_skill("force", 140);
        set_skill("xiantian-qigong", 140);    //��������
        set_skill("sword", 140);
        set_skill("quanzhen-jian",200);  //ȫ�潣
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 200);   //���㹦
        set_skill("unarmed",140);
        set_skill("parry", 140);
        set_skill("strike", 140);
        set_skill("haotian-zhang", 200);    //�����
        set_skill("cuff", 140);
        set_skill("chunyang-quan", 200);    //����ȭ
        set_skill("literate", 80);
        set_skill("taoism", 100);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();
}

#include "chu.h";

// daerba.c �����

#include <ansi.h>;

inherit NPC;

void create()
{
        set_name("�����", ({ "daerba  huofo"}));
        set("long",@LONG
���ǽ��ַ������µĴ���ӡ���÷������洫��
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "���" NOR);
        set("gender", "����");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 1200);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 150);
        set("combat_exp", 3000000+ random(1000000));
        set("score", 150000);
       set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			      
	       (: exert_function, "powerup" :),
	       (: exert_function, "regenerate" :),
	       (: exert_function, "recover" :),
	})); 

        set_skill("force",  200+ random(50));
        set_skill("xiaowuxiang",  250+ random(50));
        set_skill("dodge",  200+ random(50));
        set_skill("shenkong-xing",  300+ random(50));
        set_skill("unarmed",  200+ random(50));
        set_skill("yujiamu-quan",  300+ random(50));
        set_skill("parry",  200+ random(50));
        set_skill("sword",  200+ random(50));
        set_skill("mingwang-jian",  300+ random(50));
        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        set("class", "lama");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
}

#include "npc.h"

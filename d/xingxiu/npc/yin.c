// Room: /d/xingxiu/yin.c
// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit NPC;

void create()
{
	object ob;
	set_name("������", ({ "yin kexi", "yin", "kexi" }));
	set("title", "������");
	set("long", 
"���߱���Ŀ���������룬�Ǹ����ˣ����������������
��ⱦ�����ǲ�˹��֣����������鱦��\n");
	set("gender", "����");       
	set("age", 43);
	set("attitude","peaceful");
	set("str", 32);
	set("dex", 24);
	set("con", 26);
	set("int", 25);
	set("shen", -7000);
	set("env/wimpy", 60);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 120);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 100);
        set_skill("unarmed", 100);
        set_skill("yujiamu-quan", 80);
        set_skill("parry", 100);
        set_skill("sword", 70);
        set_skill("mingwang-jian", 60);
        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
	set("combat_exp", 750000);
	set("max_qi", 2200);
	set("max_jing", 2000);
	set("eff_jingli", 1500);
	set("jiali", 50);
	set("inquiry", ([	    
	    "���ַ���" : "�ٺ٣��ҳ������Ǹ��Ϻ��еĹ�ʦ������������", 
	]));

	set("chat_chance", 30);
	set("chat_msg", ({
	    "�������۾�����б������Ǳ�΢΢��Ц��\n",
	    (: random_move :),
	}));
	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        ob = new("clone/weapon/treasure/jinlongbian");
        if (ob->violate_unique()) destruct(ob);
        else ob->move(this_object());
}

void kill_ob(object me)
{     object ob=this_object();
      command("hehe");
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"),1);	 
      ::kill_ob(me);
}

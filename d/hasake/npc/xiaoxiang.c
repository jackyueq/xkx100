#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "xiaoxiang zi", "zi", "xiaoxiang" }));
        set("title", "��������");
        set("long", "����ĸ��ݣ�����Ѫɫ��������ʬ����������͸��һ���������ֳ�һ����ɥ����\n");
        set("gender", "����");
        set("rank_info/respect", "����");
        create_family("ؤ��", 15, "����");
        set("age", 43);
        set("attitude","heroism");
        set("str", 26);
        set("dex", 20);
        set("con", 23);
        set("int", 22);
        set("shen", -7000);
        set("env/wimpy", 60);
        set_skill("parry", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("staff", 100);
        set_skill("huntian-qigong", 120);       
        set_skill("tianshan-zhang", 120);  
        set_skill("xiaoyaoyou", 120);
        set_skill("suohou-hand", 120);
        set_skill("hand", 100);
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("hand", "suohou-hand");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("hand", "suohou-hand");
        set("combat_exp", 700000);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("eff_jingli", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("inquiry", ([            
            "���ַ���" : "�ٺ٣��ҳ������Ǹ��Ϻ��еĹ�ʦ������������",
            "�����" : "���Ǹ�ç��������ʲ��",
            "������" : "���˹��򲻴���������Ľ���̫ҫ�ۣ������������ʿ��",
            "��Ħ��" : "�������ģ��ڹ��������ǣ��ٺ٣�����̫С��",            
       ]) );
        setup();
        set("chat_chance", 45);
        set("chat_msg", ({
            "�������۾�����б������Ǳ�΢΢��Ц��\n",
            (: random_move :),  
            "�����ӵ����������书�������ã��ѵ����ϵ�����������֮���᣿�ֵܿ��е㲻�������� ����\n", 
            (: random_move :),          
        }) );
        carry_object(WEAPON_DIR"gangzhang")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();
}

void kill_ob(object me)
{     object ob=this_object();
      command("grin");
      command("say ���������ɣ�");
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
      COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));            
      ::kill_ob(me);
}

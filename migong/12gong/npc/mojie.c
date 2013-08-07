inherit NPC;
#include "star.h"
 
void create()
{
        set_name("����ŵ˹", ({"kelowooz", "mo jie"}));
        set("long", "��˵�е�����֮���ػ���Ħ����.\n");
        set("gender","����");
        set("title", "������֮��");
        set("attitude", "friendly");
        set("no_get",1);
        set("age",37);
        set("con",45);
        set("per",30);
        set("str",63);
        set("int",64);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "����ŵ˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("renma", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_neili",4000);
        set("force", 8000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_qi", 23000);
        set("max_jing", 23000);

        setup();
        carry_object(__DIR__"obj/mj_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}

void init()
{
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("$N��Цһ��������$N������ˣʲô������\n",me);
        return 1;
} 
void check()
{
        object ob=this_object();
        object ghost;
        object me2=new("/d/migong/12gong/npc/mojie2.c");
        object me=query_temp("my_killer");

        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               
     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIY"$N���ڵ��ϣ���ؾ��ҵ����ţ�\n",ob);

        if(random(3)==0)
                {
              message_vision(HIY"$N����Ķ������ᣬʧȥ��ƽ�⣡\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(HIW"$Nվ�ȽŸ�����$n���������š�\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N�ڳ���������ƣ�һ��������$n���ٷ�����\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIM"$Nһ����С�ģ�������ҧ�˸�Ѫ������\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIG"$N����Ծ�������$N�����·ɹ���\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIW"$Nҡ��һ�䣬�ֳ�����һ���Լ�����\n",ob);
        if( present("kelowooz two",environment(me)))
        return;
        me2=new(__DIR__"mojie2.c");
        me2->move(environment());
        me2->kill_ob(me);
        }
        break;
                    

  }
        if( random(30) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/renma")=="done") && (ob&&ob->query("12gong/mojie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "�����˵�ʮ��Ħ������������ƽ�սʿŬ����\n"NOR,users());
        ob->set("12gong/mojie","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"��Ӯ����20000����");

        }
       ::die();
}

inherit NPC;
#include "star.h"
 
void create()
{
        set_name("������˹", ({"adimis", "ju xie"}));
        set("long", "��˵�е�����Ů�񣭰�����˹���ػ��ž�з����\n");
        set("gender","Ů��");
        set("title", "��������");
         set("no_get",1);
        set("age",37);
        set("con",30);
        set("spi",40);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "������˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
        }));
        set("attitude", "friendly");
        set_skill("dodge", 250);
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("jinniu", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_neili", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_qi", 11000);
        set("max_jing", 11000);

        setup();
        carry_object(__DIR__"obj/jx_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               
 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }

     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(6))

     {        
        case 0:
        {
        message_vision(HIC"$N�߾�˫�֣�$n����ǰ��Ȼ���������ɲ��ˣ�\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"$N�����˳��˸������꣬���ˤ����\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(HIC"$Nһ����Ц���㿪�������ɲ��ˡ�\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N������գ�һ��Բ�º�Ȼ������$n����ǰ��\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"ԭ����һ��Բ�¾������ޱȣ�$N�����ϱ�����һ��Ѫ�ڣ�\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIC"$N��ܼ�ʱ��Բ���ڵ����Գ���һ���Ѻۡ�\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIC"$N�������һֻ��з�������������$n����ǰ��\n",ob,me);
                              
        if(random(3)==0)

                {
              message_vision(HIR"��з���һ˫����ǯ����ס��$N��\n"NOR,me);
              me->start_busy(1);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIR"$N����һ����ԭ���Ǹ�����\n"NOR,me,ob);
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

        if((ob&&ob->query("12gong/shuangzi")=="done") &&(ob&&ob->query("12gong/juxie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "�����˵��Ĺ���з����������ƽ�սʿǰ����\n"NOR,users());
        ob->set("12gong/juxie","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"��Ӯ����20000����");

        }
       ::die();
}

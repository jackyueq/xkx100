// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("��ʿ��", ({"boston", "shuang yu"}));
        set("long", "��˵�еĺ�����ʿ�٣��ػ���˫����.\n");
        set("gender","����");
        set("title", "��������");
        set("no_get",1);
        set("age",37);
        set("con",60);
        set("per",32);
        set("str",80);
        set("int",80);
        set("combat_exp",1000000);
        set("daoxing",3500000);
        set("chat_chance",20);
        set("chat_msg", ({
                "��ʿ��˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
        }));
        set_skill("dodge", 280);
        set("cant_be_smashed",1);
        set("attitude", "friendly");
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("unarmed", 280);
        set_skill("sword", 280);
        set_skill("westsword",280);
        set_skill("boxing",280);
        set_skill("balei",280);
        set_skill("spells",280);
        set_skill("shuangyu", 280);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shuangyu");
        map_skill("dodge","balei");
        set("max_neili", 4000);
        set("force", 8000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",80);
        set("force_factor", 50);
        set("max_qi", 27000);
        set("max_jing", 27000);
        setup();
        carry_object(__DIR__"obj/sy_cloth")->wear();
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
//        object rose;
        object me=query_temp("my_killer");

        if( ! me ) return ;
  
    if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(7))
     {        
        case 0:
        {
        message_vision(HIY"$Nһ���Х����֮ˮ��֮���ڣ���$n��û��\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"$N���ĺ�֮ˮײ�������������\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        message_vision(HIW"$N˳��ˮ�ƣ��ڼ������沨������\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N����һ����#$%^%!�����һֻ˫ͷ���㣡\n",ob);

        if(random(2)==0)
                {
              message_vision(HIM"�����ſ����죬����$Nһ���˺��\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIG"$Nһ����ת���Ὺ�����һ����\n"NOR,me);
         }
        break;

        case 2:
        {
        message_vision(HIC"$N�ߺ�������֮�ǣ�����֮����һ����ʯ�������$n��ȥ��\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N�������޷���ܣ�����������ʯ������û�ж�ܵĿռ䣡\n"NOR,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
              me->start_busy(1);
                }
        else
        message_vision(HIG"$N����������ò����ײŶ㿪$n�Ĺ�����\n"NOR,me,ob);
         }
        break;

        case 3:
        {
    //    rose=new("/d/12gong/npc/obj/rose.c");
        message_vision(HIC"$N��������һֻ��õ�壬ֻ��$N�촽΢������õ�������ҵļ�����$n��\n"NOR,ob,me);
  //      rose=move(environment(this_object()));
        if( ! me ) return ;
         if(random(2)==0)
                {
              message_vision(HIM"$N����õ��Ķ��̴��������壡\n"NOR,ob,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
      //        rose=move(environment());
                }
        else
        
        message_vision(HIG"$N��׼��õ������ķ���˳�ƽ�ס�˺�õ�壡\n"NOR,me);
//        rose=move(me);

         }
        break;

  }
        if( random(3) == 1 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");
        if( ! ob ) return ;
        if((ob&&ob->query("12gong/baoping")=="done") && (ob&&ob->query("12gong/shuangyu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "���ڴ����˻ƽ�ʮ������\n"NOR,users());
        ob->set("12gong/shuangyu","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"��Ӯ����20000����");
        }
       ::die();
}

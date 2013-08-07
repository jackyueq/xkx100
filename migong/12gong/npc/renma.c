// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("��˹", ({"zhou si", "ren ma"}));
        set("long", "��˵�е������˹���ػ���������.\n");
        set("gender","����");
        set("title", "����ۡ�");
        set("no_get",1);
        set("age",37);
        set("con",40);
        set("per",30);
        set("str",43);
        set("int",54);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "��˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
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
        set("max_neili", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",60);
        set("force_factor", 60);
        set("max_qi", 21000);
        set("max_jing", 21000);

        setup();
        carry_object(__DIR__"obj/rm_cloth")->wear();
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
        message_vision(HIY"$N��ָ$n��$N��ָ��ͻȻ����һ���׹⣡\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"�׹�֮��$N�е������ޱȵ���ʹ��\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(HIW"$N���޾�ɫ��һ��ת���㿪�˰׹⡣\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$Nһ�����ڣ�һֻ���˰���Ĺ�����$n�� ȥ��\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N������һ��ҧ����Ҫ����\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIG"$N����������ϸһ����ԭ��ֻ�ǻ���\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIW"$N˫�ֺ�ʮ������˫�ۣ�$n��ʱ�Ի�������\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIM"$N�о�������������ӽ��±����ߣ�\n"NOR,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
                }
        else
        message_vision(HIG"$Nվ�ȽŸ��������ںʹ�ز�����\n"NOR,me);
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

        if((ob&&ob->query("12gong/tianxie")=="done") && (ob&&ob->query("12gong/renma")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "�����˵ھŹ�����������ƽ�սʿŬ����\n"NOR,users());
        ob->set("12gong/renma","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"��Ӯ����20000����");

        }
       ::die();
}

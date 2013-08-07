// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("����˹", ({"hadis", "tian xie"}));
        set("long", "��˵�е�ڤ������˹ ���ػ�����Ы��.\n");
        set("gender","����");
        set("title", "��ڤ����");
        set("no_get",1);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "����˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
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
        set_skill("tianxie", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","tianxie");
        map_skill("dodge","balei");
        set("max_neili", 2000);
        set("neili", 24000);
        set("max_neili",22200);
        set("mana",4000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_qi", 19000);
        set("max_jing", 19000);

        setup();
        carry_object(__DIR__"obj/tx_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 
void check()
{
        object *inv;
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
        message_vision(YEL"$Nһ����Ц���޲���ɽ��������$n��ȥ����\n",ob,me);

        if(random(2)==0)
                {
              message_vision(YEL"$N�ڲ�����ҡ���ţ�\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
else        message_vision(YEL"$N�����ˮ��������ǿ�˽�����\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N����һ������һ����ɫ�Ķ�����$n��ȥ��\n",ob,me);

        if(random(2)==0)

                {
              message_vision(YEL"$N��ʱ��Ѭ����ͷ��\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(YEL"$N��ת��ͣ������һ�ᶾ����ʧ����Ӱ���١�\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N�������С����ڣ�\n",ob);
        if( present("ghost",environment(me)))
        return;
        ghost=new(__DIR__"ghost.c");
        ghost->move(environment());
        ghost->set("combat_exp",ob->query("combat_exp")/2);
        ghost->set("max_qi",ob->query("max_qi")/2);
        ghost->set("max_jing",ob->query("max_jing")/2);
        ghost->kill_ob(ob);
        message_vision(HIC"��֪�Ӻδ�����������С����$Nɱȥ��\n"NOR,me);
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

        if((ob&&ob->query("12gong/tiancheng")=="done") && (ob&&ob->query("12gong/tianxie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "�����˵ڰ˹�����Ы����������ƽ�սʿŬ����\n"NOR,users());
        ob->set("12gong/tianxie","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"��Ӯ����20000����");

        }
       ::die();
}

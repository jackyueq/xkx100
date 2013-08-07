// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("����ŵ˹", ({"woolanus", "bao ping"}));
        set("long", "��˵�е����֮���ػ��ű�ƿ��.\n");
        set("gender","����");
        set("title", "�����֮��");
        set("no_get",1);
        set("age",37);
        set("con",55);
        set("per",30);
        set("str",73);
        set("int",64);
        set("combat_exp",4000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "����ŵ˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
        }));
        set_skill("dodge", 350);
        set("attitude", "friendly");
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("sword", 350);
        set_skill("westsword",350);
        set_skill("boxing",350);
        set_skill("balei",350);
        set_skill("spells",350);
        set_skill("renma", 350);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_neili", 5000);
        set("force", 10000);
        set("max_mana",7000);
        set("mana",14000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_qi", 25000);
        set("max_jing", 25000);

        setup();
        carry_object(__DIR__"obj/bp_cloth")->wear();
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
        message_vision(HIY"$N�߾ٱ�ƿ��һ��쫷���$n�Ľ�������\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"$N�����Ϳ��Ʋ�ס�Լ����������Ȼ�������ص�ˤ����������\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(HIW"$N�����³�����ǿ����ס$n��쫷硣\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIC"$NͻȻ�����ȥ��Ȼ�������������$n����������\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N��Ȼ��$n�������´���֮��,$N��æ�ӵ���ת�˳�����\n"NOR,me,ob);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
              me->start_busy(1);
                }
        else
        message_vision(HIG"$N�͵�һ����$nһͷ�Ե����¡�\n"NOR,me,ob);
        ob->start_busy(1);
         }
        break;

        case 2:
        {
        message_vision(HIC"$N�������б�ƿ����ƿ�����������ʯ��ֱ��$n��\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N��ʯͷ���˸�ͷ��Ѫ����\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
              me->start_busy(1);
                }
        else
        message_vision(HIG"$N�����λ����ʯͷ����ɱ��һ��Ѫ·��\n"NOR,me);
         }
        break;

        case 3:
        {
        message_vision(HIW"$N����һ����������ȣ�ֻ��һ�ɺ���ֱϮ$n\n"NOR,ob,me);

        if(random(2)==0)
                {
              message_vision(HIW"$N���������У�����֫����ľ���ƺ�Ҫ����һ�㣡\n"NOR,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
              me->start_busy(1);
                }
        else
        message_vision(HIW"$N��ͣ���˶��Լ������壬�Ա���һ����ů��\n"NOR,me);
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

        if((ob&&ob->query("12gong/mojie")=="done") && (ob&&ob->query("12gong/baoping")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "�����˵�ʮһ����ƿ������ƽ�սʿŬ����\n"NOR,users());
        ob->set("12gong/baoping","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"��Ӯ����20000����");

        }
       ::die();
}

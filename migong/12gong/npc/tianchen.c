// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("ͯ��", ({"tong hu", "tian chen"}));
        set("long", "��˵����®ɽ���Ϸ徲��0243����й������\n");
        set("gender","����");
        set("title", "����ʥ��");
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
                "ͯ��˵����ֻ���й�������õĹ���\n",
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("staff", 250);
        set_skill("lunhui-zhang",250);
        set_skill("jienan-zhi",250);
        set_skill("lotusmove",250);
        set_skill("spells",250);
        set_skill("buddhism", 250);
        map_skill("staff","lunhui-zhang");
        map_skill("unarmed","jienan-zhi");
        map_skill("spells","buddhism");
        map_skill("dodge","lotusmove");
        set("max_neili", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",60);
        set("force_factor", 60);
        set("max_qi", 17000);
        set("max_jing", 17000);

        setup();
        carry_object(__DIR__"obj/tc_cloth")->wear();
        carry_object(__DIR__"obj/tc_staff")->wear();
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

     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(5))
     {        
        case 0:
        {
        message_vision(HIC"$N��һ����®ɽ�����ԡ�һ�������Ծ������ֱ��$n��\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"$N�������ڿ��ж��÷��˼�ʮ����ͷ��\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else        message_vision(HIG"$N���ͼ�ת����֪�����˶���Ȧ�Ŷ�������Ĺ�����\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N�ߺ�һ������®ɽ�����ԡ���һ�������Խ��׶�����β����$nɨȥ��\n",ob,me);

        if(random(2)==0)
                {
              message_vision(GRN"$N��������β��˦�˸����ţ�$N��ʱ��ð���ǣ�\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIY"$N�þ�ȫ������������������������β������$N�Ľŵװ�ɨ����\n"NOR,me);

        } 
        break;

        case 2:
        {

        message_vision(HIR"$N�ߺ�һ������®ɽ�����ԡ�������ֻ������$n�������\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIR"$N��һ����һ����������ֻ�����ڿ���ϷŪ�ţ�\n"NOR,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
                }
        else
        message_vision(HIR"$N��׼�˾���֮��Ŀ�϶����ת��ת������ǿ���ѣ�\n"NOR,me,ob);
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

        if((ob&&ob->query("12gong/shinu")=="done") && (ob&&ob->query("12gong/tiancheng")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "�����˵��߹�����ӹ�!\n"NOR,users());
        ob->set("12gong/tiancheng","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"��Ӯ����20000����");

        }
       ::die();
}

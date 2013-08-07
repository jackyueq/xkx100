//mu.c
#include <ansi.h>
inherit NPC;
int ask_zhou();

void create()
{
        set_name("ľ����", ( { "mu daozhu", "mu" }) );
        set("title", HIB"���͵�����"NOR);
        set("gender", "����" );
        set("age", 60);
        set("long","���Ǹ���������ʮ����ĺ��ӣ���üȫ�ף��������ݣ���һϮ���ۣ���Ȼͦ����\n");

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);
        set("no_get",1);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set("qi",20000);
        set("max_qi", 20000);
        set("jing", 20000);
        set("max_jing", 20000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 300);
        set("combat_exp", 3000000);
        set("score", 250000);

        set_skill("force", 300);
        set_skill("taixuan-gong", 300);
        set_skill("dodge", 300);
        set_skill("tiyunzong", 300);
        set_skill("unarmed", 300);
        set_skill("taiji-quan", 300);
        set_skill("parry", 300);
        set_skill("taoism", 200);
        set_skill("literate", 100);

        map_skill("force", "taixuan-gong");
        map_skill("dodge", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
        map_skill("parry", "taixuan-gong");

        set("chat_chance", 3);
        set("chat_msg", ({
            "ľ������Ȼһ���Դ���˵����������Ǻö����ۣ�\n",
            "ľ����˵������ô��ô���Ӣ��Ҳ��������̫�����ء�\n",
        }) );
        set("inquiry", ([
            "������" : (: ask_zhou :),
            "���͵�" :  "\n��������Һ����ֵ������з��ֵġ�\n",
        ]));
        create_family("���͵�", 1, "����");
        setup();

 //       carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if(ob->query_skill("literate",1)>50)
              say ("ľ����������ҡ��ҡͷ��˵��������̫�ࡣ\n");
        return;
}

int ask_zhou()
{
        say(
"\nľ��������˵�����Ǳ������еĶ���������Ҫ��һζ'�ϳ�ʴ�Ǹ��Ĳ�'���ɣ�\n"
"Ҫ������Ч�������������ֲ�ÿʮ��ſ�һ�λ������������������\n"
"һ���˺��ѵõ��ģ�С�ֵ���Ҫ��Ҫ�����Ե���ˣ�\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obn;

        if (  ob->query("id") != "shane bu" && ob->query("id") != "fuxin cao")
        {
                message_vision("\nľ����ҡͷ�����ⲻ������Ҫ��ѽ��\n",who);
                return 0;
        }
        if ( ob->query("id") == "shane bu" )
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("ľ����ҡͷ�����ҿ�С�ֵܽ����ڴ���Ե��\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("cao"))
                        {
                                message_vision("\nľ�����������Ʒ��񲾣���ϲ������ϲ��λС�ֵ���!\n",who);
                                obn=new("/clone/medicine/nostrum/labazhou");
                                obn->move(who);
                                delete_temp("bu");
                                delete_temp("cao");
                                return 1;
                        }
                        else if(query_temp("bu"))
                        {
                                message_vision("\nľ�����������Ʒ��񲾣���$Nҡͷ�������Ʒ��������ˡ�\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","ľ�����������Ʒ��񲾣���ϲ��������ֻ��Ĳ��ˡ�\n",environment(who));
                                set_temp("bu",1);
                                return 1;
                        }
                }
        }
        if ( ob->query("id") == "fuxin cao")
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("ľ����ҡͷ�����ҿ�С�ֵܽ����ڴ���Ե��\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("bu"))
                        {
                                message_vision("\nľ�������Ǹ��Ĳݣ���ϲ������ϲ��λС�ֵ���!\n",who);
                                obn=new("/clone/medicine/nostrum/labazhou");
                                obn->move(who);
                                delete_temp("cao");
                                delete_temp("bu");
                                return 1;
                        }
                        else if(query_temp("cao"))
                        {
                                message_vision("\nľ�������Ǹ��Ĳݣ���$Nҡͷ�������Ĳ����Ѿ����ˡ�\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","ľ�����������Ĳݣ���ϲ��������ֻ�����Ʒ����ˡ�\n",environment(who));
                                set_temp("cao",1);
                                return 1;
                        }
                }
        }
        return 1;
}

int recognize_apprentice(object ob)
{

        message_vision("$Nҡ��ҡͷ��\n",this_object());
        command("tell "+ob->query("id")+"���ǲ��յ��ӵģ�����Ե�ʯ������ѧ�ۣ�\n");
        return 0;
}
int accept_hit(object me)
{
	command("say �����˱��Ժ�ʤ��ȴҲ��ֳ��ϡ�");
	return notify_fail("");
}
int accept_kill(object who)		{return accept_hit(who);}
int accept_ansuan(object who) {return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}

int accept_fight(object ob)
{
        object me;
        me = this_object();
        if (me->is_fighting())
         {
         	command("say �����ڱ����У����Ժ�\n");
         	return notify_fail("");
         	}
        if(me->query("eff_qi") < me->query("max_qi") || 
           me->query("qi") < me->query("eff_qi") ||
           me->query("neili") < me->query("max_neili")){
           me->set("eff_qi",me->query("max_qi"));
           me->set("qi",me->query("max_qi"));
           me->set("neili",me->query("max_neili"));
           }
        if( ob->query_temp("pending/fight") ) {
        ob->delete_temp("pending/fight");
        message_vision(CYN"$n��$N˵���ðɣ����ҿ������Ƿ����ʸ�ѧ̫���񹦡�\n"NOR, ob, me);
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        if (!ob->is_busy())
        ob->start_busy(1);
        return 1;
        }
        else return 0;
}
int checking(object me, object ob)
{
        object good;
        int my_max_qi, his_max_qi;
           seteuid(getuid());
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");
        if (me->is_fighting()){
                call_out("checking",1, me, ob);
                return 1;
                }
        if ( !present(ob, environment()) ) return 1; 
        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
        	  ob->set_temp("winner",1);
            message_vision("$N��$n��ס����̾����λ"+RANK_D->query_respect(ob)+"��Ȼ��ͬ���죬���������ѧϰ̫�����ˡ�\n"NOR, me, ob);
            return 1;
            }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ){
                message_vision("$N����$n΢Ц������Ĺ�����ǳ�������Ŭ������\n"NOR, me,ob);
                return 1;
               }
        return 1;
}
// /clone/quest/bwdhnpc.c
// Modified by sir 2004-01-20

#include <dbase.h>
#include <login.h>
#include <ansi.h>

inherit NPC;
inherit F_CLEAN_UP;
inherit F_UNIQUE;

void create()
{	
	set_name("����",({ "di zi" }) );
	set("gender", random(2)>0 ? "Ů��" : "����" );
	set("attitude", "friendly");
	set("chat_chance", 30);
        set("chat_msg", ({
	  (:call_out,"random_move",0:),
        	}) );       	      
	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
        carry_object("/clone/food/jiudai");
}

int random_move()
{
        mapping exits;
        string *dirs, dir, dest;

        if( !mapp(exits = environment()->query("exits")) ) return 0;
        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        dest = exits[dir];
        if( find_object(dest)->query("no_fight")) return 0;
        if( this_object()->is_fighting() ) return 0;
        command("go " + dir);
        return 1;
}

void init()
{	
	object ob;
	if ( interactive(ob=this_player())) {
			remove_call_out("killing");
			call_out("killing", 0, ob);
		}
	 add_action("do_hit","hit");
	 add_action("do_hit","kill");	 
	 add_action("do_hit","touxi");
	 add_action("do_hit","ansuan");
	 add_action("do_hit","steal");	 	 
}

void killing(object ob)
{	
	message_vision("$N����$n�ȵ�����"+RANK_D->query_rude(ob)+"�����첻������������������\n",this_object(),ob);
	this_object()->kill_ob(ob);	
        return;
}

int do_hit(string arg)
{
	object ob = this_object(), me = this_player();
        mapping map_status;
        string*	mname;
        int i,j;
        mixed perform_actions = ({});
        mixed combat_actions = ({});
        mixed msg =({});
        if (!arg || (arg != ob->query("id") ) )
		return 0;
        if ( mapp(map_status = ob->query_skill_map()) ) 
           {
			mname  = keys(map_status);
	
			for(i=0; i<sizeof(map_status); i++) 
			{
				perform_actions = get_dir( SKILL_D(map_status[mname[i]]) + "/" );
				for ( j = 0; j < sizeof( perform_actions ); j++ )
				{
					sscanf( perform_actions[j], "%s.c", perform_actions[j] );
					if ( mname[i] == "force" )
						msg = ({ (: exert_function, perform_actions[j] :) });
					else
						msg = ({ (: perform_action, mname[i] + "." + perform_actions[j] :) });
					combat_actions += msg;
				}
			}
		}
		ob->set( "chat_chance_combat", 40);		
		ob->set( "chat_msg_combat", combat_actions );		
	       if((int)me->query("combat_exp")>(int)ob->query("combat_exp"))
                
               ob->set("combat_exp",(int)me->query("combat_exp")); 
               ob->fight_ob(me); 

}
void die()
{
        object ob = this_object();
        object me,fme;
        int pot,exp,level,score;
        me = ob->query_temp("last_damage_from");
        fme = ob->query_temp("last_opponent");
        if( fme && me->query("id")==fme->query("id"))        
        {         
         pot = 300 + random(100);
         exp = 800 + random(300);
         score = 300 + random(100);
         me->add("combat_exp",exp);
         me->add("potential",pot);
         me->add("score",score);
         me->add_temp("bwdh_nknum",1);
        message_vision("$N������޺޵�˵���������ʱ������̸��¸��У���\n",ob);
        tell_object(me,HIW"�����۽���սʤ���֣��õ����½�����\n");
        tell_object(me,chinese_number(exp) +"��ʵս����\n" +
        chinese_number(pot) + "��Ǳ�ܡ�\n"NOR);
       } 
       destruct ( ob );
//        ::die();    
}

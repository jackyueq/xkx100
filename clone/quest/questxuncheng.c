// /clone/quest/questyinshi.c
//// Last Modified by sir on 4.20.2002

#include <dbase.h>
#include <login.h>
#include <ansi.h>

inherit NPC;
inherit F_CLEAN_UP;
inherit F_UNIQUE;
string * name_msg = ({
        "���",
        "С͵",
        "��ɮ",
        "Сë��",
        "��",
        "ɽ��",
        "����",
        "��ū",
        "����",
        "С���",
        "�ɻ���",
        "������",
        "��ؤ",
        "����",
        "����",
        "����",
});
string * long_id = ({
        "e ba",
        "xiao tou",
        "e seng",
        "xiao maozei",
        "zui han",
        "shan zei",
        "man bing",
        "e nu",
        "tu fei",
        "xiao hunhun",
        "caihua zei",
        "mengmian ren",
        "e gai",
        "e shang",
        "dao ke",
        "jian ke",
});

void create()
{
        int i;
        i = random(sizeof(name_msg));
        set_name(name_msg[i], ({ long_id[i]}) );
        set("gender", random(2)>0 ? "Ů��" : "����" );
        set("attitude", "friendly");
        set("max_qi",2000+random(1000));
        set("max_jing",1000+random(500));
        set("int", 30);
	set("str", 30+random(30));
	set("con", 30);
	set("dex", 30+random(30));
  
    /*   set("chat_chance", 60);
        set("chat_msg", ({
          (:call_out,"random_move",0:),
        }) );
       */
        set("chat_chance_combat", 60);
	set("chat_msg_combat", ({			
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );
        set("no_steal", 1);
        setup();
        carry_object("/d/city/npc/obj/tiejia")->wear();
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
	object ob, me;
	me= this_object();
	if(interactive(ob = this_player()) && living(this_object()))
	  if(me->query("owner")==ob->query("id"))
		{	 
			command("kao " + ob->query("id"));
			ob->start_busy(1+random(3));
			command("say ������쵰��û������Ѳ�ǣ��ҹܴ�ү���£�");
			command("kick "+ ob->query("id"));						}
         add_action("do_hit","hit");
         add_action("do_hit","kill");    
         add_action("do_hit","touxi");
         add_action("do_hit","ansuan");
         add_action("do_hit","steal");   
         add_action("do_halt","halt");
         add_action("do_halt","go");
         add_action("do_halt","surrender");
	 add_action("do_look","look");
}

int do_look(string arg)
{
        object ob = this_object();
        object me = this_player();
        if (!arg || arg != ob->query("id") )
                return 0;

        else
        {
          message_vision( ob->query("name") + "��ȵ�����ʲô���������\n",me);
          return 1;
        }

}

           
int do_hit(string arg)
{
        object ob = this_object();
        object me = this_player();
        int i,j;
        if (!arg || arg != ob->query("id") )
                return 0;              
         if (!(me->query("id")==ob->query("owner")))
        {
                if (userp(me) )
                {
                        tell_object(me,HIW"������Ҫץ���ˣ���ʲô���֣�\n"NOR);
                        return 1;
                }
                else return 0;
        }
  
}

int do_halt()
{
        object me = this_player();
        object ob = this_object();
        
        if ( me->is_fighting(ob))
        {
                message_vision(HIW"$N�ȵ������ٺ٣����ܣ����ֳ���������ô�У���\n"NOR, ob, me);
                return 1;
        }
        return 0;
}
void die()
{
        object ob = this_object();
        object me;
        int pot,exp,score;
        me = query_temp("last_damage_from");       
        if( ob->query("owner")==me->query("id")
        && (int)me->query_condition("dali_xuncheng"))
        me->add_temp("xuncheng_kill_num",1);            
         ::die();    
}

// migong lev5

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIY"���"NOR, ({ "jin diao" , "diao" }));
                set("race", "Ұ��");
       set("long",
"һֻ���Ž�ɫ��ë�Ĵ��
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw" }) );
	       set("max_qi",9000+random(2000));
  set("max_jing",9000+random(2000));
  set("max_sen",9000+random(2000));
  set("max_mana",9000+random(2000));
  
      set("dex",100);
     set("str" ,100);
       
    set("age", 15);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 3000000);
                  
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/defence", 200);

   setup();

    
carry_object("/d/migong/obj/tao");
	    

}


void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}



void hunting()
{
	int i;
        object *ob;
if (!environment(this_object())) return;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        message_vision(WHT"$Nž��һ��̱���ڵ��ϡ�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 700000)   {
if (random(80) < 1)
{
             corpse=new("/clone/gem/gem");
             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+corpse->query("name")+"!"NOR"��\n");
             corpse->move(killer);
}        
        message("vision", me->name() + "�ɹ���������������400�����200Ǳ�ܡ�\n", me);
        me->add("combat_exp",400);
        me->add("potential",200);
        destruct(ob);
        }
              me->add("score",1);
               destruct(ob);
        return;
}



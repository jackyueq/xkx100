// migong lev3

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name("毒蟾蜍", ({ "chan chu" , "chan" }));
      
          set("race", "野兽");
       set("long",
"满身疙瘩，丑陋不堪的癞蛤蟆。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体" }) );
        set("verbs", ({ "bite" }) );
	       set("max_qi",1000+random(800));
  set("max_jing",1000+random(800));
  set("max_sen",1000+random(800));
  set("max_mana",1000+random(800));
  
      set("dex",40);
     set("str" ,45);
       
    set("age", 5);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 1100000);
                  
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",100);

   setup();

        

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
        
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 400000)   {
        message("vision", me->name() + "成功打死猎物增加了50经验和25潜能。\n", me);
        me->add("combat_exp",50);
        me->add("potential",25);
        destruct(ob);
        }
              me->add("score",1);
               destruct(ob);
        return;
}



int hit_ob(object me, object ob, int damage)
{
   if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("chanchu_poison") < 10 ) {
		ob->apply_condition("chanchu_poison", 20);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
	}
}


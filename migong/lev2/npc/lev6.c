// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(WHT"ɱ�˷�"NOR, ({ "sharen feng", "feng" }));
      
          set("race", "Ұ��");
       set("long",
"һֻ��ɫ���۷䣬����ͨ��Ҫ���Ϻü� ��
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����" }) );
        set("verbs", ({ "bite" }) );
	       set("max_qi",800+random(500));
  set("max_jing",800+random(500));
  set("max_sen",800+random(500));
  set("max_mana",800+random(500));
  
      set("dex",40);
     set("str" ,20);
       
    set("age", 5);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 700000);
                  
        set_temp("apply/attack", 70);
        set_temp("apply/damage", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/defence",70);

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
        
        message_vision(WHT"$Nһͷ�Ե��ڵ��ϡ�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 100000)   {
        message("vision", me->name() + "�ɹ���������������40�����20Ǳ�ܡ�\n", me);
        me->add("combat_exp",40);
        me->add("potential",20);
        destruct(ob);
        }
              me->add("score",1);
               destruct(ob);
        return;
}

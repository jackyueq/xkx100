// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(BLU"����"NOR, ({ "nie long" , "long" , "dragon" }));
                set("race", "Ұ��");
       set("long",
"һ����ª�������ײ��ޱȵľ�����
���������������Ѩ����پ�������ѹ�֣�������ʮ�ֵؿ���
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",50000+random(20000));
  set("max_jing",50000+random(20000));
  set("max_sen",50000+random(20000));
  set("max_mana",500000+random(20000));
  
      set("dex",100);
      set("con",100);
     set("str" ,120);
       
    set("age", 150);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 10000000+random(2000000));
            set_temp("apply/attack", 600);
        set_temp("apply/damage", 600);
        set_temp("apply/armor", 600);
        set_temp("apply/defence",600);
      set_skill("dodge", 600+random(100));

      set_skill("unarmed", 600+random(100));

       set_skill("dragon", 600+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.yaoyao" :),

   (: perform_action, "unarmed.tuwu" :),

 }) );
     
   setup();

    
    carry_object("/d/migong/obj/dan2");
	    

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
        
        message_vision(WHT"$Nһ��ŭ�𣬻�����Ѫֱ���������ɵ��ڵء�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 900000)   {
        message("vision", me->name() + "�ɹ���������������600�����250Ǳ�ܡ�\n", me);
        me->add("combat_exp",500);
        me->add("potential",250);
        destruct(ob);
        }
              me->add("score",1);
               destruct(ob);
        return;
}


int hit_ob(object me, object ob, int damage)
{
   if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("wugong_poison") < 10 ) {
		ob->apply_condition("wugong_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n" NOR );
	}
}

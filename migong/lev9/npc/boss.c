// migong lev9 boss

#include <ansi.h>

inherit NPC;


void create()
{
  
        set_name(WHT"������"NOR, ({ "jiguan ren" , "ren" }));
 
set("title", HIG"�ɶ��칦"NOR);
   set("gender", "����" );
 set("long",
"һ�߽�ʵ���־��µĻ����ˡ�\n");
         set("force_factor",100+random(200));
  set("max_qi",999999+random(99999));
  set("max_jing",99999+random(99999));
  set("max_sen",99999+random(99999));
  set("max_neili",99999+random(99999));
  set("max_mana",99999+random(99999));
  set("eff_neili",9999+random(9999));
  set("neili",9999+random(9999));
        set("per", 1);
        set("age", 32);

       set("str" , 100);
       set("jiali" , 100);
        set("shen", -10000);
        
        set("combat_exp", 3500000+random(1200000));
                 set_skill("unarmed", 330+random(50));

 set_skill("taixuan-gong", 330+random(50));

set_skill("force", 330+random(50));
set_skill("parry", 330+random(50));

set_skill("dodge", 330+random(50));

  
        map_skill("unarmed", "taixuan-gong");
  
      map_skill("parry", "taixuan-gong");

 map_skill("force", "taixuan-gong");

 map_skill("dodge", "taixuan-gong");
 
prepare_skill("unarmed", "taixuan-gong");
set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
              	
         (: exert_function, "recover" :),
	    }) );
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
 
          set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
  
  	

}


// migong lev12  xuantie-jian

#include <ansi.h>

inherit NPC;


string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",

"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});


void create()
{
  
       int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "jianmo dizi" , "dizi" }));
 
set("title", HIC"��ħ����"NOR);
   set("gender", "����" );
 set("long",
"��ħ���״����ӡ�\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",3000+random(3000));
  set("max_jing",3000+random(3000));
  set("max_sen",3000+random(3000));
  set("max_neili",3000+random(3000));
  set("max_mana",3000+random(3000));
  set("eff_neili",3000+random(3000));
  set("neili",3000+random(3000));
        set("per", 1);
        set("age", 42);

       set("int", 20);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 6000000+random(2000000));
                 set_skill("unarmed", 400+random(100));

set_skill("xuantie-sword", 400+random(100));

set_skill("yunv-shenfa", 400+random(100));

set_skill("force", 400+random(100));
set_skill("anranxiaohun-zhang", 400+random(100));
set_skill("sword", 400+random(100));

set_skill("parry", 400+random(100));

set_skill("hubo", 400+random(100));

set_skill("dodge", 400+random(100));

set_skill("xuantie-jianfa", 400+random(100));

set_skill("yunv-xinfa", 400+random(100));

  
        map_skill("sword", "xuantie-jianfa");
  
      map_skill("parry", "xuantie-jianfa");

 map_skill("force", "yunv-xinfa");

 map_skill("dodge", "yunv-shenfa");
 
map_skill("unarmed"  , "anranxiaohun-zhang");
prepare_skill("unarmed", "anranxiaohun-zhang");
set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               
      (:     perform_action, "sword.xunlei" :),
	
           (: command("hubo")  :),	
         (: exert_function, "recover" :),
        (: exert_function, "powerup" :),
      }) );
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
 
          set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/sword")->wield();

	add_money("gold", random(5));
	

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
        
        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 7000000)   {
        message("vision", me->name() + "Ϊ��������,������600�����250Ǳ�ܡ�\n", me);
        me->add("combat_exp",600);
        me->add("potential",250);
        destruct(ob);
        }
             me->add("score",1);
        me->add("shen",10);
        destruct(ob);
        return;
}

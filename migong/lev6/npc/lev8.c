// migong lev6 ��罣 

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
 ({ "man" }));
 
set("title", HIC"����ͽ"NOR);
   set("gender", "����" );
 set("long",
"����ʦ�ţ����������ķ�ͽ��\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",1500+random(1500));
  set("max_jing",1500+random(1500));
  set("max_sen",1500+random(1500));
  set("max_neili",1500+random(1500));
  set("max_mana",1500+random(1500));
  set("eff_neili",1500+random(1500));
  set("neili",1500+random(1500));
        set("per", 1);
        set("age", 22);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 1200000+random(500000));
                 set_skill("strike", 210+random(40));

set_skill("huashan-zhangfa", 210+random(40));

set_skill("huashan-neigong", 210+random(40));

set_skill("zixia-shengong", 210+random(40));

set_skill("force", 210+random(40));

set_skill("parry", 210+random(40));

set_skill("dodge", 210+random(40));

set_skill("kuangfeng-jian", 210+random(40));

set_skill("sword", 210+random(40));

set_skill("feiyan-huixiang", 210+random(40));

  
        map_skill("sword", "kuangfeng-jian");
  
      map_skill("parry", "kuangfeng-jian");

 map_skill("force", "zixia-shengong");

 map_skill("dodge", "feiyan-huixiang");
 
map_skill("strike"  , "huashan-zhangfa");
prepare_skill("strike", "huashan-zhangfa");
set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
               
      (: perform_action, "sword.feilong" :),
	
  (: perform_action, "sword.kuanglong" :),
	
         (: perform_action, "dodge.huiyanfeiwu" :),
	
     (: exert_function, "recover" :),
     (: exert_function, "powerup" :),
    }) );
            set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
 
          set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/sword")->wield();
		add_money("gold", random(2));


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
        if((int)me->query("combat_exp") < 1500000)   {
        message("vision", me->name() + "Ϊ��������,������150�����50Ǳ�ܡ�\n", me);
        me->add("combat_exp",150);
        me->add("potential",50);
        destruct(ob);
        }
             me->add("score",1);
        me->add("shen",10);
        destruct(ob);
        return;
}

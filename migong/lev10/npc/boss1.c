// migong lev10  qz

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
 ({ "bailei" }));
 
set("title", HIY"ȫ�����"NOR);
   set("gender", "����" );
 set("long",
"����ʦ���汻���ʦ�ŵ�ȫ����֡�\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",3500+random(2000));
  set("max_jing",3500+random(2000));
  set("max_sen",3500+random(2000));
  set("max_neili",3500+random(2000));
  set("max_mana",3500+random(2000));
  set("eff_neili",3500+random(2000));
  set("neili",3500+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 4000000+random(2000000));
                set_skill("strike", 360+random(60));

 set_skill("qixing-array", 360+random(60));

 set_skill("array", 360+random(60));

set_skill("xiantian-qigong", 360+random(60));

set_skill("force", 360+random(60));
set_skill("sword", 360+random(60));

set_skill("parry", 360+random(60));

set_skill("dodge", 360+random(60));

set_skill("quanzhen-jian", 360+random(60));

set_skill("haotian-zhang", 360+random(60));

set_skill("jinyan-gong", 360+random(60));

  
        map_skill("sword", "quanzhen-jian");
 
        map_skill("array", "qixing-array");
   
      map_skill("parry", "quanzhen-jian");

 map_skill("force", "xiantian-qigong");

 map_skill("dodge", "jinyan-gong");
 
map_skill("strike"  , "haotian-zhang");
prepare_skill("strike", "haotian-zhang");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
 
          (: exert_function, "recover" :),
    (: exert_function, "xiantiandafa" :),
          (: perform_action, "sword.qixinglianzhen" :),

      (: command("wield jian") :),
     (: command("wield jian") :),		
 }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
 
          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

carry_object("/d/migong/obj/sword")->wield();
  
carry_object("/d/migong/obj/sword");
  
carry_object("/d/migong/obj/sword");
      
  add_money("gold", random(3));
 	

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
        
if (!me) return;
        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 5000000)   {
if (random(50) < 1)
{
             corpse=new("/clone/gem/gem");
             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+corpse->query("name")+"!"NOR"��\n");
             corpse->move(killer);
}        
        message("vision", me->name() + "Ϊ��������,������400�����150Ǳ�ܡ�\n", me);
        me->add("combat_exp",400);
        me->add("potential",150);
        destruct(ob);
        }
             me->add("score",1);
        me->add("shen",10);
        destruct(ob);
        return;
}

// migong lev10  du

#include <ansi.h>

inherit NPC;


void create()
{
  
      set_name(MAG"ä����"NOR,({ "mang popo" , "popo" }));
 
       set("gender", "Ů��" );
 set("long",
"�ٶ������ʦ��,�书���ߣ��򱻰ٶ�������㶾Ϲ��
˫�ۣ����Զ���ڴΡ�\n");
        	  set("force_factor",100+random(200));
  set("max_qi",9000+random(2000));
  set("max_jing",9000+random(2000));
  set("max_sen",9000+random(2000));
  set("max_neili",9000+random(2000));
  set("max_mana",9000+random(2000));
  set("eff_neili",2500+random(2000));
  set("neili",9000+random(2000));
        set("per", 1);
        set("age", 52);

       set("jiali" , 200);
        set("shen", -10000);
               set("combat_exp", 8000000+random(2000000));
                 set_skill("claw", 400+random(60));

set_skill("unarmed", 400+random(60));

set_skill("huagong-dafa", 400+random(60));

set_skill("force", 400+random(60));
set_skill("sanyin-wugongzhao", 360+random(60));

set_skill("parry", 400+random(60));

set_skill("poison", 400+random(60));

set_skill("dodge", 400+random(60));

set_skill("chousui-zhang", 400+random(60));

set_skill("tianshan-zhang", 400+random(60));

set_skill("staff", 400+random(60));

set_skill("zhaixinggong", 400+random(60));

  
        map_skill("unarmed", "chousui-zhang");
  
        map_skill("unarmed", "tianshan-zhang");
 
      map_skill("parry", "tianshan-zhang");

 map_skill("force", "huagong-dafa");

 map_skill("dodge", "zhaixinggong");
 
map_skill("claw"  , "sanyin-wugongzhao");
prepare_skill("claw", "sanyin-wugongzhao");
prepare_skill("unarmed", "chousui-zhang");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               
     (: perform_action, "staff.tianshan" :),
	
      (: perform_action, "staff.hushen" :),
	
       (: perform_action, "unarmed.zhaohuo" :),
	
     (: perform_action, "unarmed.zhaohuo" :),
	
     (: perform_action, "unarmed.yinhuo" :),
	
    (: perform_action, "unarmed.huoqiu" :),
	
          (: exert_function, "recover" :),
    (: exert_function, "powerup" :),
 }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
 
          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);


   set("inquiry", ([       
"�ٶ����" : "������ʦ�ܣ�������Ĺ��ϵĶ������ҵ��۾���������Ϲ�ġ�",
"�ٶ�����" : "�ٶ�����Ҳ����ʦ�ܣ���Ҳ���Ǹ��ö���������ʦ���Ǳ�Ϊ�顣",
"�۾�" : "�ҵ��۾��Ǳ��ϳ��ݶ�Ϲ�ģ�ֻ�����ĺ������Ρ�",
"���ĺ���" : "��˵���ĺ��ľ�ֻ�����������У�����������þ���û�ҵ���"
]) );  

        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/zhang")->wield();
	
    

}

int accept_object(object who, object ob)
{
	   if ((string)ob->query("id")=="qixin haitang") {
            say(MAG"ä����"NOR"�����Ľе����������첻����,�������ܱ����ˣ���
˵��ʹҴ�ææ�뿪�ˡ�
\n");
           move("/d/migong/lev8/dong101");
            }
		return 1;
}
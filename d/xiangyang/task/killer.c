// Last Modified by sir 2003.11.14
#include <ansi.h>
inherit NPC;

int do_back(object me);

void create()
{
	set_name("������", ({ "heiyi ren","ren"}));
	set("gender", "����");
	set("quest_no_guard",1);
	set("no_steal",1);
	set("no_ansuan",1);
	set("long", "һ�����ź�ɫҹ���µ��ˡ�\n");
	set( "chat_chance_combat", 80);         
        set( "chat_msg_combat",({
        		(: exert_function, "recover" :),
        		(: exert_function, "powerup" :),
           }) );
	setup();
	carry_object("/d/city/obj/tiejia")->wear();
	call_out("do_back", 360,  this_object());
}

int do_back(object me)
{			
	if (objectp(environment(me)))
	{
		tell_room(environment(me), me->query("name")+"�Ҵ�ææ���뿪�ˡ�\n", ({me}));	
		destruct(me); 
	}
  return 1;
}

	void die()
		{
        object ob = this_object();
        object me,fme;
        int pot,exp,level,score;
        me = ob->query_temp("last_damage_from");
        fme = ob->query_temp("last_opponent");
        if( objectp(me) && objectp(fme) && me->query("id")==ob->query("owner") 
             && me->query("id")==fme->query("id"))        
        {
			   exp=400+random(200);
				 pot=exp*3/10+random(60)-30;
 //        score =300+random(50);
         me->add("combat_exp",exp);
         me->add("potential",pot);
//         me->add("score",score);
	me->set_temp("prize_reason","��ʿ");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",exp);
	me->set_temp("prize_pot",pot);
	       me->delete_temp("guoys_mis_target");
	       me->delete_temp("guoys_mis_given");
	       me->delete_temp("guoys_mis_flag");
	       me->clear_condition("guoys_mis");	

        tell_object(me,HIW"��ɹ��ر�������ʿ�İ�ȫ��\n�㱻�����ˣ�\n");
        tell_object(me,chinese_number(exp) +"��ʵս����\n" +
        chinese_number(pot) + "��Ǳ��\n"NOR);
       } 
        ::die();    
   }

int accept_hit(object me)
{
	if( this_object()->query("owner") == me->query("id")) 
	{
		if (!this_object()->is_fighting(me)) this_object()->kill_ob(me);
		return 1;
	}
	else return notify_fail(HIW"������Ҫץ���ˣ���ʲô���֣�\n"NOR);
}
int accept_fight(object who)	{return accept_hit(who);}
int accept_kill(object who)		{return accept_hit(who);}
int accept_ansuan(object who) {return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}
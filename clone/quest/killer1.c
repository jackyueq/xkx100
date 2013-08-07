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
	NAME_D->generate_cn_name(this_object());
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
	object *obs;
	int pot,exp,level,score;
	int all_exp,all_pot;
	int per_exp,per_pot;
	int i;

	all_exp=200+random(200);
	all_pot=all_exp*3/10+random(60)-30;
	
	obs = ob->query_temp("killer");
	if (!sizeof(obs)) return ::die();

	fme = ob->query_temp("faint_by");
	
	per_exp = all_exp / (sizeof(obs)+2);
	per_pot = all_exp / (sizeof(obs)+2);

	for (i=0;i<sizeof(obs);i++)
	{
		if( objectp(obs[i]) && environment(obs[i])==environment(ob) )
		{
			exp = per_exp;
			pot = per_pot;
			if (obs[i]==fme)
			{
					exp += per_exp;
					pot += per_pot;
			}
			if (obs[i]->query("id")==ob->query("owner"))
			{
					exp += per_exp;
					pot += per_pot;
			}
			me->add("combat_exp",exp);
			me->add("potential",pot);
			me->set_temp("prize_reason","׷ɱ");
			me->set_temp("can_give_prize",1);
			me->set_temp("prize_exp",exp);
			me->set_temp("prize_pot",pot);

			tell_object(me,HIW"�����ⷬ������\n�㱻�����ˣ�\n");
			tell_object(me,chinese_number(exp) +"��ʵս����\n" +
			chinese_number(pot) + "��Ǳ��\n"NOR);
		}
	}
	me = find_player(ob->query("owner"));
	if (objectp(me))
	me->set("quest/kill/finished",1);
  ::die();    
}

int accept_fight(object ob)
{
        add_temp("killer",ob);
        command("say �ã����ǾͱȻ��Ȼ���");
        kill_ob(ob);
        return 1;
}

int accept_hit(object ob)
{
        add_temp("killer",ob);
        command("say ����ȥ�ɣ�");
        kill_ob(ob);
        return 1;
}

int accept_kill(object ob)
{
        add_temp("killer",ob);
        command("say �ߣ�������");
        return 1;
}
int accept_ansuan(object who) {return notify_fail("���˾�����̫�ߣ�û�����㡣\n");}
int accept_touxi(object who)	{return accept_kill(who);}
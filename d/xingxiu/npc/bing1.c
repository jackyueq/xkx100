// Room: /d/xingxiu/npc/bing.c
// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�߷��ٱ�", ({ "guan bing", "bing" }));
	set("age", 32);
	set("gender", "����");
	set("long", "���Ǹ�����פ������ı߷�����\n");
	set("attitude", "peaceful");
	set("str", 33);
	set("int", 16);
	set("con", 25);
	set("dex", 20);
	set("no_get",1);
	set("combat_exp", 30000);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);	
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/d/city/obj/junfu")->wear();
}

int accept_fight(object me)
{
	command("say ��ү���ر߹��۵�Ҫ����û�պ�"+RANK_D->query_respect(me)+"�����档\n");
	return 0;
}

void init()
{
	object ob, me, money;

	::init();
	ob = this_player();
	if (!interactive(ob)) return;
	if (!living(ob)) return;
	if (ob->query_temp("ride_horse")) return;
	if((int)ob->query_condition("killer") || ob->query_temp("xx_rob"))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
	else if(random(50)<=1)
		{
			me=this_object();	 
			command("say ���"+RANK_D->query_rude(ob)+"����վס�����м�飡");
			if(ob->query("guanbing"))
			{
				ob->add("guanbing", -1);
				message_vision(HIY"$n����$N���˰��죬�������������$N���ߡ�\n"NOR, ob, me);
				return;
			}
			message_vision(HIY"$n��$N��ס����$N���������˰��졣\n"NOR, ob, me);
			ob->start_busy(5);
			if(money = present("gold_money", ob))
			{
				money->move(me);
				ob->add("guanbing", 2);
				tell_object(ob, HIR "����㷢�ֱ߷��ٱ��������ϵĻƽ������ˣ�\n"NOR);
			}
			else if(money = present("silver_money", ob))
				{
					money->move(me);
					ob->add("guanbing", 1);
					tell_object(ob, HIR "����㷢�ֱ߷��ٱ��������ϵİ��������ˣ�\n"NOR);
				}
			else command("say �������⵰��������ˮ��û�У����ҹ���");
			command("kick "+ ob->query("id"));		
		}
}

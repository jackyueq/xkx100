// chacha.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIW "�й���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIW "�йٶ���˵����ι�������ˣ�\n\n" NOR,
	HIW "�й١��ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIW "�йٺ��ϲ��ӣ�˵�����ţ�������δ������ô�ܵ��������ˣ�\n\n" NOR,
	HIW "�й�ɦ��ɦͷ��̾�������˰��ˣ��㻹�ǻ�����ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
	set_name(YEL "�й�" NOR, ({ "pan guan","guan" }) );
	set("long", @LONG
������˾��ִ�ƹܴ��ڹ���ʩ����֮�٣��������ż�������������������
LONG);
	set("gender","����");
	set("str",1000);
	set("title",HIW "���˾" NOR);			
	set("attitude", "peaceful");
	set("age", 1000);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	set("max_neili",10000);
	set("neili",10000);
	setup();
	carry_object( __DIR__"obj/shsbu" )->wear();
}


void init()
{
	object ob;
	::init();
	if( !(ob=previous_object())||!userp(ob)) 
		return;
	if(!ob->is_ghost() && !wizardp(ob)) 
	{
		command("say ι��������������ʲ�᣿");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
	call_out( "check_rein",2, ob);
}

void check_rein(object ob)
{
	int mud_age, rein_time;
	mud_age=(int)ob->query("mud_age");
	rein_time=(int)(ob->query("PKS") * 20) + (int)(ob->query("MKS") / 10);
	if((int)ob->query("age")<=15 || mud_age>=rein_time)
	{
		remove_call_out("death_stage");
		call_out("death_stage" ,1,ob,0);
	}
}

void death_stage(object ob, int stage)
{
	object *obs, mailbox;
	int i;

	if( !ob || !present(ob) ) return;
	if( stage != 4 )
		tell_object(ob, death_msg[stage]);
	else
	{
		obs = deep_inventory(ob);
		if(sizeof(obs))
		{
			command("hmm");
			tell_object(ob,HIW"�й�˵��������������Ķ����ǲ��ܴ�������ģ�����Ҫ�������ϵĶ�������������\n"NOR);
			return;
		}
		else
			tell_object(ob,death_msg[stage]);
	}
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 3, ob, stage );
		return;
	}
	ob->reincarnate();
	obs = all_inventory(ob);
	for (i = 0; i < sizeof(obs); i++)
		DROP_CMD->do_drop(ob, obs[i]);
	if (!mailbox=present("mailbox",ob))
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(ob);
  if (time()-ob->query_temp("LAST_PKER_TIME")<7200)
       ob->move("/d/city/shilijie4");
   else
      ob->move(REVIVE_ROOM);
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}


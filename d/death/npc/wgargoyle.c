// gargoyle.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIW "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
	HIW "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIW "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIW "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
	HIW "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
	set_name(HIW"���޳�"NOR, ({ "white gargoyle", "gargoyle" }) );
	set("long",
		"���޳�������������ͷ�����㣬���׵����Ͽ������κ�ϲŭ���֡�\n");
//	set("nickname",HIR"�����޳�"NOR);
//	set("title","ڤ��ʹ��");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
//		(: this_object(), "random_move" :),
		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",
		"���޳��ѳ�������ͷ��������������������Լ��ְ��ֳ�����ָ��\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_qi", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object())
	||	(wizardp(previous_object()) && !previous_object()->query("no_look_wiz"))) 
	return;
	remove_call_out("death_stage");
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv, mailbox;
	if( !ob || !present(ob) ) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

 if (!wizardp(ob))
 {
        inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
                DROP_CMD->do_drop(ob, inv[i]);
	}
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



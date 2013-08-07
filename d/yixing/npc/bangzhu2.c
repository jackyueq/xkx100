// /d/yixing/npc/bangzhu2.c
// Last Modified by winder on Jul. 12 2002

#define BANGZHONG2 "/d/yixing/npc/bangzhong2"

inherit NPC;

#include <ansi.h>
#include <localtime.h>

#include "/d/yixing/doc/info_bang.h"

void create()
{
	set_name("���Ϸ�", ({ "bangzhu" }));
	set("gender", "����");
	set("age", 30);
	set("long", "һ������֮���Ĵ󺺣����Ӽ�����ɣ������ȴ�����塣\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("combat_exp", 60000);

	set("max_qi", 300);
	set("max_jing", 200);
	set("max_qi", 600);
	set("max_neili", 200);
	set("neili", 200);

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("cuff", 80);
/*
	set_skill("ding-force", 80);
	map_skill("force", "ding-force");

	set_skill("wuxingbu", 80);
	map_skill("dodge", "wuxingbu");
*/
	set("no_get", "����̫����");

	setup();

	call_out("come_attacker", 10);
}

void init()
{
	::init();

	add_action("do_ask", "ask");
}

int do_ask(string arg)
{
	object ob, me = this_object();
	string dest, topic;

	if( !arg || sscanf(arg, "%s about %s", dest, topic) != 2 ) {
		write("��Ҫ��˭ʲô�£�\n");
		return 1;
	}

	if( !objectp(ob = present(dest, environment(me))) ) {
		write("����û������ˡ�\n");
		return 1;
	}

	if( ob != me )
		return notify_fail("");

	if( !living(me) )
		return 1;

	say(name() + "��ŭ����û���������˲������أ���������\n");
	return 1;
}

void come_attacker()
{
	object me = this_object(), helper, *myenemy, room, ob, obj;
	string *bangs;
	int temp, bonus, record;

	if( !(room = environment()) ) {
		destruct(me);
		return;
	}

	if( !(helper = query("helper")) ) {
		say(name() + "������������˵ز��ɾ�������ʮ������Ϊ�ϣ�\n");
		say(name() + "����ææ���뿪�ˡ�\n");
		destruct(me);
		return;
	}

	if( room != environment(helper) ) {
		say(name() + "������������˵ز��ɾ�������ʮ������Ϊ�ϣ�\n");
		say(name() + "����ææ���뿪�ˡ�\n");
		destruct(me);
		return;
	}

	if( !is_fighting() &&  living(me)
	&&  explode(base_name(room), "/")[1] == (string)query("dest") ) {
		command("thumb " + helper->query("id"));
		if( obj = present("bang ling", helper) ) {
			bonus = (int)obj->query("job/bonus");
			bonus = bonus * 100000 / ( 100000 + (int)helper->query("combat_exp") );
			record = bonus/2 + random(bonus);
			helper->add("combat_exp", record);
			log_file("BangJob", sprintf("%s��%sʱ�򻤼��й���%s�����\n", helper->query("name"), ctime(time()), chinese_number(record)));
			bonus /= 4;
			obj->add("score", bonus);
			obj->delete("job");
		}
		say(name() + "˫��һ��ȭ������������Ҫ��һ��ʱ�䣬�����Ϊ֮�ɣ�\n");
		say(name() + "�ﳤ��ȥ��\n");
		destruct(me);
		return;
	}

	remove_call_out("come_attacker");
	call_out("come_attacker", 5 + random(5));

	if( room->query("no_fight") ) return;

	if( temp = sizeof(myenemy = query_enemy()) ) {
		for(int i = 0; i < temp; i++)
			if( myenemy[i]->query("victim") == me )
				return;
	}

	ob = new(BANGZHONG2);
	bangs = keys(info_bang);
	bangs -= ({query("fam")});
	ob->set("title", bangs[random(sizeof(bangs))]);
	ob->set("victim", me);

	ob->move(room);
	message("vision",
		ob->name() + "���˹�����\n",
		room, ({ob}));
	ob->set_leader(me);
	message_vision("$N��$n�ȵ������㻹�������ܣ���\n", ob, me);
	ob->kill_ob(me);
	command("!!!");
	me->kill_ob(ob);
}
	

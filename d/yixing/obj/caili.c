// /d/yixing/obj/caili.c  ����
// Last Modified by winder on Jul. 12 2002


#include  <ansi.h>
#include <command.h>
#include <changle.h>
inherit ITEM;
#include D_BANG

void create()
{
	set_name(RED"����"NOR, ({ "caili" }));
	set("weight", 20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"����һ�ݰ�װ���ƵĲ�������һ��װ�Ź��صĶ�����\n");
		set("unit", "��");
		set("value", 30);
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");	    
	}

	setup();

	call_out("do_check", 1 + random(20));
}


// to avoid players from cheating
// like go by da che or let other players carry them
// like go by following another player or driven by another player

// i still think, it is better to change follow.c and sing.c files
// then will save source

void do_check()
{
	object owner, room;

	if( !(owner = query("owner")) ) {
		destruct(this_object());
		return;
	}

	if( !living(owner)
	||  owner->query_leader() 
	||  owner->query_temp("cursed", 1) ) {
		tell_object(owner, HIR"\n���Ȼ��һ�ֲ���ĸо���\n"NOR);
		destruct(this_object());
		return;
	}

	call_out("do_check", 1 + random(20));
}

void init()
{
	add_action("do_go", "go");
	add_action("do_visit", "visit");
	add_action("do_giveup", "giveup");
}

int do_go(string arg)
{
	object me = this_player(), ob, room;
	string *bangs;
	int ap, dp;

	if( me->is_busy() ) {
		write("����æ�š�\n");
		return 1;
	} 

	room = environment(me);

	if( ob = present("bang zhong", room) ) {
		if( living(ob) ) {
			ap = (int)me->query("combat_exp");
			dp = 3 * (int)ob->query("combat_exp");
     // leave a trick here for smarter players
			if( random(ap + dp) > dp )
				return 0;

			me->start_busy(1);
			message_vision("$N��$n�ȵ���" + RANK_D->query_rude(me) + "�Ѷ������£�����\n", ob, me);
			if( !ob->is_fighting(me) )
				ob->kill_ob(me);
			return 1;
		}
	}

	if( random(4) ) {
		me->receive_damage("jing", 30 + random(30), 1,"��������");
		me->receive_damage("qi", 30 + random(30), 1,"��������");
		tell_object(me,"������һ������е����ˡ�\n");
		return 0;
	}

	ob = new(BANGZHONG2);
	bangs = keys(info_bang);
	bangs -= ({(string)me->query("party/party_name")});
	ob->set("title", bangs[random(sizeof(bangs))]);

	ob->move(room);
	message("vision",
		ob->query("title") + ob->name() + "���˹�����\n",
		environment(ob), ({ob}));
	message_vision(HIR"\n" + ob->query("title") + ob->name() + "��$N�ȵ���" + RANK_D->query_rude(me) + "�Ѷ������£�����\n"NOR, me);    
	ob->kill_ob(me);
	me->start_busy(1);
	return 1; 
}

int do_visit(string arg)
{
	object room, ob, me = this_player(), obj;
	int bonus, record;
	mapping job;

	if( me->is_busy() || me->is_fighting() ) {
		write("����æ�š�\n");
		return 1;
	}

	if( !arg ) {
		write("��Ҫ�ݷ�˭��\n");
		return 1;
	}

	if( !mapp(job = query("job")) ) {
		destruct(this_object());
		return 1;
	}

   // the following is very important to avoid players cheating
	room = environment(me);
	if( base_name(room) != job["file"] ) {
		write("�㻹û��Ŀ�ĵ��ء�\n");
		return 1;
	}

	if( !(ob = present(arg, room)) ) {
		write("���û����Ҫ�ݷõ��ˡ�\n");
		return 1;
	}

	if( ob->query("name") != job["name"] ) { 
		write("��ݷô����ˡ�\n");
		return 1;
	}

	if( !living(ob) ) {
		write("�㻹�ǵȴ���������˵�ɡ�\n");
		return 1;
	}

	if( ob->is_busy() || ob->is_fighting() ) { 
		write("������æ�š�\n");
		return 1;
	}

	message_vision("$N��$n�������˸�Ҿ������˵�����װ������" + RANK_D->query_self_rude(me) + "��һ�ݴ����" + RANK_D->query_respect(ob) + "��\n", me, ob);
	message_vision("$N��" + name() + "˫�ַ��$n��\n", me, ob);
	move(ob);
	remove_call_out("do_destroy");
	call_out("do_destroy", 1, this_object());

	message_vision("$N����һ����˵����" + RANK_D->query_respect(me) + "�����ˡ���ȥ�������������ʸ�����\n", ob);

	bonus = (int)job["bonus"] * 400000 / (200000 + me->query("combat_exp"));
	record = bonus + random(bonus);
	me->add("combat_exp", record);
	write_file("/log/test/BangJob", sprintf("%-10s��%-20sʱ�������%-5s�����\n", me->query("name"), ctime(time()), chinese_number(record)));

	bonus /= 4;
	me->add("shen", -bonus);

	if( obj = present("bang ling", me) ) {
		if( obj->query("owner") == me->query("id") )
			obj->add("score", bonus);
			obj->delete("job");
	}

	return 1;
}

void do_destroy(object ob)
{
	if(ob) destruct(ob);
}

int do_giveup()
{
	object ob;

	if( ob = present("bang zhong", environment(this_player())) ) {
		if( base_name(ob) == BANGZHONG2 && living(ob) ) {
		message_vision("$N����ʧ���س�̾һ����˵������Ȼ��ˣ�Ҳ�Ͱ��ˣ�\n", this_player());
		message_vision("$N�������͸�$n��\n", this_player(), ob);
		message("vision",
		ob->name() + "˵��������ʶʱ���Ҿ�����һ����˵����ﳤ��ȥ��\n",
		environment(ob), ({ob}));
		destruct(ob);
		destruct(this_object());
		return 1;
		}
	}
	return notify_fail("��û�����٣�����\n");
}

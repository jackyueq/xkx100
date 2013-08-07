// /d/yixing/obj/bangling.c
// Last Modified by winder on Jul. 12 2002

#include <changle.h>
#define BANGZHU BANGS"npc/bangzhu"

#include <ansi.h>
#include <localtime.h>

inherit ITEM;

#include D_STORE

void create()
{
	set_name("����", ({ "bang ling", "ling" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����г��õİ��\n");
		set("value", 0);
		set("material", "wood");
		set("partyname", HIC"���ְ�"NOR);
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
	}
	setup();
}

void init()
{
	add_action("do_collect", "collect");
	add_action("do_sign", "sign");
	add_action("do_find", "find");
	add_action("do_bargain", "bargain");
}

int do_find(string arg)
{
	object *obj, room;
	string file, region, fam, result;
	int i;
	mapping job;

	if( (string)query("owner") != this_player()->query("id") )
	{
	       write("�����Լ��İ���ܲ��ã������뿪���ɡ�\n");
	       return 1;
	}
	if( !stringp(fam = this_player()->query("party/party_name")) )
	{
	       write("��û�м����ᡣ\n");
	       return 1;
	}
	if( arg == "score" )
	{
		write("������" + chinese_number((int)query("changle/score")) + "�㹦�͵㡣\n");
		return 1;
	}
	if( arg != "job" )
	{
    return 0;
	}

	if( !mapp(job = query("changle/job")) )
	{
		write("������û�б�ָ�ɰ���\n");
		return 1;
	}

	result = "�㵱ǰ�İ�����";
	switch(job["type"]) {
	case "Ѱ":
		result += "��" + job["name"]; 
		break;
	case "ɱ":
		result += "ɱ" + job["area"] + "��" + job["name"]; 
		break;
	case "̯��":
		result += "Ҫ" + job["name"] + "��̯��";
		break;
	case "����":
		result += "��" + job["name"] + "����";
		break;
	case "ʾ��":
		result += "��" + job["name"] + "ʾ��";
		break;
	case "����":
		result += "�����" + job["area"] + "��" + job["title"];
		break;
	case "����":
		result += "���Ͱ�����" + job["dest"];
		break;
	case "����":
		result += "��" + job["name"] + "�����ü�Ǯ";
		break;
	case "���":
		result += "���챦�������";
		break;
	default:
		write("������û�б�ָ�ɰ���\n");
		return 1;
	}

	write(result + "��\n");
	return 1;     
}

int do_collect(string arg)
{
	object me = this_player();
	object victim, obj;
	int ap, dp, myexp, yourexp, bonus, record;
	mapping job;

	if( time() < (int)query("collect_time") + random(10) )
		return notify_fail("��������Ҫ��Ǯ��\n");
	if( (int)me->query("qi") < 50 || (int)me->query("jing") < 50 )
		return notify_fail("��̫���ˣ���Ъ�����\n");
	if( (string)query("owner") != me->query("id") )
		return notify_fail("��������Ϲ�ã�\n");
	if( (string)query("fam") != me->query("party/party_name") )
		return notify_fail("���Ѿ����Ǵ˰�����ˡ�\n");
	if( !mapp(job = query("changle/job")) )
		return notify_fail("������û�а������\n");
	if( job["type"] != "̯��" )
		return notify_fail("�㵱ǰ�İ�������̯�ѡ�\n");
	if( base_name(environment(me)) != job["place"] )
		return notify_fail("�㻹û��" + job["name"] + "��ʲô̯�ѣ�\n");
	if( !arg ) return notify_fail("��Ҫ��˭����Ǯ��\n");
	if( !(victim = present(arg, environment(me))) )
		return notify_fail("���û������ˡ�\n");
	if( victim->name() != job["boss"] )
		return notify_fail("���Ҵ����ˡ�\n");
	if( !living(victim) )
		return notify_fail("�㻹�ǵȴ���������������Ǯ�ɡ�\n");
	if( victim->is_busy() || victim->is_fighting() )
		return notify_fail("������æ�š�\n");

	message_vision(HIR"\n$N��$n����ߺ�ȵ�������" + (string)query("fam") + "����̯�ѵģ�ʶʱ��ĸϿ��Ǯ������\n"NOR, me, victim);

	me->receive_damage("qi", 20 + random(10));
	me->receive_damage("jing", 20 + random(10));

	set("collect_time", time());

	myexp = (int)me->query("combat_exp");
	ap = (int)query("combat_exp") + myexp * 10;

	yourexp = (int)victim->query("combat_exp");
	if( yourexp < 30000 ) yourexp = 30000;
	dp = yourexp * 30;
 
	if( random(ap + dp) < dp )
	{
		message_vision("$N��ŭ����ʲô" + (string)query("party/party_name") + "���������������\n", victim);
		return 1;
	}
	message_vision("$N��$n˵����" + RANK_D->query_respect(me) + "�����ˣ���һ��̯����С�ĸø��ġ�\n", victim, me);
	message_vision("$N����˵����" + RANK_D->query_respect(me) + "����ģ����������˽�Ǯ�͵�������\n", victim);

	bonus = 1 + yourexp * 2 / (myexp + 10000);
	record = bonus + random(bonus);
	me->add("combat_exp", record);
	log_file("test/BangJob", sprintf("%-10s��%-20sʱ����̯�ѵ�%-5s�����\n", me->query("name"), ctime(time()), chinese_number(record)));

	bonus /= 4;
	me->add("shen", -bonus);
	add("score", bonus);
	return 1;
}

int do_sign(string arg)
{
	object obj, room;
	object me = this_player();
	int bonus, record;
	mapping job;

	if( query("owner") != me->query("id") )
		return 0;
	if( (string)query("fam") !=
		(string)me->query_temp("party/party_bname") )
		return 0;
	if( !arg || arg != "corpse" || !(obj = present(arg, environment(me))) )
		return 0;
	if( !mapp(job = query("job")) )
	{
		tell_object(me, "������û�а���\n");
		return 1;
	}
	if( obj->query("kill_by") != me ||
		obj->query("signed") ||
		(string)obj->query("victim_name") != job["name"] )
		return 0;

	obj->set("signed", 1);
	bonus = job["bonus"] * job["max"] / (1000 + me->query("combat_exp"));
	record = bonus + random(bonus);
	me->add("combat_exp", record);
	log_file("test/BangJob", sprintf("%-10s��%-20sʱɱ%-10s��%-5s�����\n", me->query("name"), ctime(time()), job["name"], chinese_number(record)));

	bonus = job["score"];
	me->add("shen", -bonus);
	add("score", bonus);

	message_vision("$N��ʬ����д�¡���" + (string)query("fam") + "Ϊ����ɱ�����������֡�\n", me);
	delete("job");
	return 1;
}

int do_bargain(string arg)
{
	object target, obj, me = this_player();
	mapping job;
	int bonus, exp;

	if( (string)query("owner") != me->query("id") )
		return notify_fail("��������Ϲ�ã�\n");
	if( (string)query("fam") != me->query("party/partyname") )
		return notify_fail("���Ѿ����Ǵ˰�����ˡ�\n");
	if( !mapp(job = query("changle/job")) )
		return notify_fail("������û�а������\n");
	if( !arg ) return notify_fail("��Ҫ��˭�ּۻ��ۣ�\n");
	if( !(target = present(arg, environment(me))) )
		return notify_fail("���û������ˡ�\n");
	if( !living(target) )
		return notify_fail("�㻹�ǵȴ�����������˵��\n");
	if( userp(target) )
		return notify_fail("��Ҳ�����ü�Ǯ�ġ�\n");
	if( target->is_busy() || target->is_fighting() )
		return notify_fail(target->name() + "��æ�š�\n");
	if( (exp = (int)target->query("combat_exp")) < 10000 )
	{
		message_vision("$N���˰���˵�������������������˰ɡ�\n", target);
		return 1;
	}
	if( !(obj = present(job["good"], me)) )
		return notify_fail("���" + job["name"] + "Ū���ˡ�\n");
	if( time() < (int)target->query("trader/time") + 600 ) {
		message_vision("$N���˰���˵�����Ҹ�����һ" + obj->query("unit") + obj->name() + "��\n", target);
		return 1;
	}
	if( (bonus = (int)job["prices"][explode(base_name(environment(target)), "/")[1]]) < 5 ) {
		message_vision("$N���˰���˵�����ⶫ�������ڴ˵�һ��Ҳ��ֵǮ�����Լ��ðɡ�\n", target);
		return 1;
	}
	target->set("trader/time", time());
	bonus *= (1 + (int)target->query("combat_exp") / 100000);
	message_vision("$N������˵�����ðɣ�" + chinese_number(bonus) + "�����ӣ��ٹ��Ҳ����ˡ�\n", target);
	message_vision("$N���˵�ͷ����" + obj->query("unit") + obj->name() + "����$n��\n", me, target);
	obj->move(CANGKU);
	message_vision("$N˵�����´ι������ʱ���ٸ��\n", target);
	message_vision("$N˵����û��ϵ���´λ��и��õĻ���\n", me);

	bonus /= 20;
	me->add("combat_exp", bonus);
	log_file("test/BangJob", sprintf("%-10s��%-20sʱ����%-10s��%-5s�����\n", me->query("name"), ctime(time()), obj->name(), chinese_number(bonus)));
	add("score", bonus/4);
	delete("job");
	return 1;
}

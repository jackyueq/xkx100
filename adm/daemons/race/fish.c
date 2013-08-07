// fish.c ����
// Last Modified by winder on Aug. 1 2002

#ifndef __FISH__
#define __FISH__

// A normal fish is at least 20 g weight
#define BASE_WEIGHT 20
#endif

inherit F_DBASE;

mapping *combat_action = ({
([
	"action":	"$N��������������$n��$l�ݺݵ�һҧ",
	"damage":	20,
	"damage_type":	"ҧ��",
]),
([
	"action":	"$N�ڶ�β����$n��$l�͵�һ��",
	"damage":	20,
	"damage_type":	"����",
]),
});

void create()
{
	seteuid(getuid());
	set("attitude", "peaceful");
	set("limbs", ({
		"ͷ��",	"����",	"����",	"����",	
		"ǰ��",	"����", "β��"
	}) );

	set("dead_message", "\n$N�ڶ��˼��£��װ׵Ķ������Ϸ���������\n\n");
	set("unconcious_message", "\n$N�ڶ��˼��£������������ⷭ�˳�����\n\n");
	set("revive_message", "\n$N���˼��£�����ˮ�����˿�ȥ��\n\n");
	set("comeout_message", "���˸�ˮƯ����$d���˳�ȥ��\n");
	set("comein_message", "���˹�������ˮ�����ش��˸�ת����\n");
	set("fleeout_message", "���˸�ˮƯ����$d���˳�ȥ��\n");
	set("fleein_message", "ҡͷ��β�����˹������װ׵Ķ������Ϸ��š�\n");
}

void setup_fish(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

	my["unit"] = "��";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random(5) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(10) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random( 5) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random( 5) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(10) + 5;
	if( undefinedp(my["dex"]) ) my["dex"] = random(20) + 5;
	if( undefinedp(my["kar"]) ) my["kar"] = random(10) + 5;

	if( undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 10 ) my["max_jing"] = my["age"] * 5;
		else my["max_jing"] = 50;
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 10 ) my["max_qi"] = my["age"] * 8;
		else my["max_qi"] = 80;
	}
	if( undefinedp(my["max_jingli"]) ) {
		if( my["age"] <= 10 ) my["max_jingli"] = my["age"] * 10;
		else my["max_jingli"] = 100;
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 5)* 500);
}

mapping query_action(object me)
{
	return combat_action[random(sizeof(combat_action))];
}

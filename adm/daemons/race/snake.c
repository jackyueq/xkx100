// snake.c ����
// Last Modified by winder on Aug. 1 2002

#ifndef __SNAKE__
#define __SNAKE__

// A normal beast is at least 1 g weight
#define BASE_WEIGHT 1
#endif

inherit F_DBASE;

mapping *combat_action = ({
([
	"action":	"$N������������$n��$l�ݺݵ�һҧ",
	"damage":	30,
	"damage_type":	"ҧ��",
]),
([
	"action":	"$N֧�����͵���$n��$l��������",
	"damage":	30,
	"damage_type":	"����",
]),
([
	"action":	"$N�������ס��$n����һ��",
	"damage":	30,
	"damage_type":	"����",
]),
});

void create()
{
	seteuid(getuid());
	set("attitude", "agressive");
	set("limbs", ({
		"ͷ��", "����", "�ߴ�", "β��"
	}) );

	set("dead_message", "\n$Nʹ���Ť���˼��£�ȫ�������ɢ�˿�����\n\n");
	set("unconcious_message", "\n$Nʹ���Ť�˼��£������ˡ�\n\n");
	set("revive_message", "\n$N����һ��һ�������ڵ��ϵ������߿�����\n\n");
	set("comeout_message", "ವ�һ������$d���˳�ȥ��\n");
	set("comein_message", "���ѵ����˹�����\n");
	set("fleeout_message", "ವ�һ������$d���˳�ȥ��\n");
	set("fleein_message", "���������˹����������ǵ��ڵ���ſ�š�\n");
}

void setup_snake(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

	my["unit"] = "ֻ";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random(10) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(20) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random(10) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random(10) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(30) + 5;
	if( undefinedp(my["dex"]) ) my["dex"] = random(20) + 5;
	if( undefinedp(my["kar"]) ) my["kar"] = random(10) + 5;

	if( undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 20 ) my["max_jing"] = my["age"] * 5;
		else my["max_jing"] = 100;
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 20 ) my["max_qi"] = my["age"] * 8;
		else my["max_qi"] = 160;
	}
	if( undefinedp(my["max_jingli"]) ) {
		if( my["age"] <= 20 ) my["max_jingli"] = my["age"] * 10;
		else my["max_jingli"] = 200;
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action(object me)
{
	return combat_action[random(sizeof(combat_action))];
}

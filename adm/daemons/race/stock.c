// stock.c ����
// Last Modified by winder on Aug. 1 2002

#ifndef __LIVESTOCK__
#define __LIVESTOCK__

// A normal LIVESTOCK is at least 100 kg weight
#define BASE_WEIGHT 100000
#endif

inherit F_DBASE;

mapping *combat_action = ({
([
	"action":	"$N�ú�����$n��$l����һ��",
	"damage":	30,
	"damage_type":	"����",
]),
([
	"action":	"$N����ͷ��$n��$l�͵�һײ",
	"damage":	30,
	"damage_type":	"����",
]),
([
	"action":	"$Ņ��ǰ����$n��$l�ݺݵ�һ��",
	"damage":	20,
	"damage_type":	"����",
]),
});

void create()
{
	seteuid(getuid());
	set("attitude", "friendly");
	set("limbs", ({
		"ͷ��",	"����",	"�ز�",	"��",	"����",	
		"ǰ��",	"����", "ǰ��",	"����", "β��"
	}) );

	set("dead_message", "\n$N��˻һ�������������˼��²����ˡ�\n\n");
	set("unconcious_message", "\n$N������˻��ƹ��һ��ˤ���ڵ��ϡ�\n\n");
	set("revive_message", "\n$N����������һ�£���˻һ����վ��������\n\n");
	set("comeout_message", "��$d��ȥ��\n");
	set("comein_message", "С�����˹����������н����̤���ŵ��档\n");
	set("fleeout_message", "��˻һ������$d��Ķ��ӡ�\n");
	set("fleein_message", "ҡҡ�ڰڵ����˹������ǿ�����������Ű�����\n");
}

void setup_stock(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

	my["unit"] = "ֻ";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(30) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random(20) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random(20) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(40) + 5;
	if( undefinedp(my["dex"]) ) my["dex"] = random(20) + 5;
	if( undefinedp(my["kar"]) ) my["kar"] = random(10) + 5;

	if( undefinedp(my["max_jing"]) )
	{
		if( my["age"] <= 3 ) my["max_jing"] = 50;
		else if( my["age"] <= 10 ) my["max_jing"] = 50 + (my["age"] - 3) * 20;
		else if( my["age"] <= 30 ) my["max_jing"] = 190 + (my["age"] - 10) * 5;
		else my["max_jing"] = 290 + (my["age"] - 30) * 2;
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 5 ) my["max_qi"] = 100;
		else if( my["age"] <= 20 ) my["max_qi"] = 100 + (my["age"] - 5) * 20;
		else my["max_qi"] = 400 + (my["age"] - 20) * 5;
	}
	if( undefinedp(my["max_jingli"]) ) {
		if( my["age"] <= 3 ) my["max_jingli"] = 150;
		else if( my["age"] <= 20 ) my["max_jingli"] = 150 + (my["age"] - 3) * 40;
		else my["max_jingli"] = 830 + (my["age"] - 20) * 10;
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action(object me)
{
	return combat_action[random(sizeof(combat_action))];
}

// beast.c Ұ��
// Last Modified by winder on Aug. 1 2002

#ifndef __BEAST__
#define __BEAST__

// A normal beast is at least 50 kg weight
#define BASE_WEIGHT 50000
#endif

inherit F_DBASE;

mapping *combat_action = ({
([
	"action":	"$N������������$n��$l�ݺݵ�һҧ",
	"damage":	50,
	"damage_type":	"ҧ��",
]),
([
	"action":	"$N����צ����$n��$lץ�˹�ȥ",
	"damage":	30,
	"damage_type":	"ץ��",
]),
([
	"action":	"$NԾ������ǰ����$n��$l�͵�һ��",
	"damage":	30,
	"damage_type":	"����",
]),
});

void create()
{
	seteuid(getuid());
	set("attitude", "aggressive");
	set("limbs", ({
		"ͷ��",	"����",	"�ز�",	"��",	"����",	
		"ǰ��",	"����", "ǰצ",	"��צ", "β��"
	}) );

	set("dead_message", "\n$N����Һ���һ����ſ�ڵ��ϲ����ˡ�\n\n");
	set("unconcious_message", "\n$N�͵͵غ���һ���������ڵ����˹�ȥ��\n\n");
	set("revive_message", "\n$N��֫����������һ�£����������˹�����\n\n");
	set("comeout_message", "��$d���˹�ȥ��\n");
	set("comein_message", "���ش��˳�������������������š�\n");
	set("fleeout_message", "�ҽ�һ������$d��Ķ��ӡ�\n");
	set("fleein_message", "ҡҡ�ڰڵ����˹����������ͷ�����ش��Ŵ�����\n");
}

void setup_beast(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

	my["unit"] = "ֻ";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random(40) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(40) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random(10) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random(30) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(40) + 5;
	if( undefinedp(my["dex"]) ) my["dex"] = random(40) + 5;
	if( undefinedp(my["kar"]) ) my["kar"] = random(20) + 5;

	if( undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 3 ) my["max_jing"] = 50;
		else if( my["age"] <= 10 ) my["max_jing"] = 50 + (my["age"] - 3) * 20;
		else if( my["age"] <= 30 ) my["max_jing"] = 190 + (my["age"] - 10) * 5;
		else my["max_jing"] = 290 + (my["age"] - 30) * 2;
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 5 ) my["max_qi"] = 50;
		else if( my["age"] <= 20 ) my["max_qi"] = 50 + (my["age"] - 5) * 25;
		else my["max_qi"] = 425 + (my["age"] - 20) * 5;
	}
	if( undefinedp(my["max_jingli"]) ) {
		if( my["age"] <= 3 ) my["max_jingli"] = 100;
		else if( my["age"] <= 20 ) my["max_jingli"] = 100 + (my["age"] - 3) * 50;
		else my["max_jingli"] = 950 + (my["age"] - 20) * 10;
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action(object me)
{
	return combat_action[random(sizeof(combat_action))];
}

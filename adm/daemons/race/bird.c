// bird.c ����
// Last Modified by winder on Aug. 1 2002

#ifndef __BIRD__
#define __BIRD__

// A normal bird is at least 50 g weight
#define BASE_WEIGHT 50
#endif

inherit F_DBASE;

mapping *combat_action = ({
([
	"action":	"$N��צ����$n��$l�͵�һץ",
	"damage":	10,
	"damage_type":	"ץ��",
]),
([
	"action":	"$N�ɹ�����$n��$l�ݺݵ�һ��",
	"damage":	30,
	"damage_type":	"����",
]),
([
	"action":	"$N�ó����$n��$l���˹�ȥ",
	"damage":	30,
	"damage_type":	"����",
])
});

void create()
{
	seteuid(getuid());
	set("attitude", "peaceful");
	set("limbs", ({
		"ͷ��",	"����",	"��",	"����",	"��צ",	"���"
	}) );

	set("dead_message", "\n$N����һ�����������У��Ӱ���е���������\n\n");
	set("unconcious_message", "\n$N�Ӱ������ص����������˹�ȥ��\n\n");
	set("revive_message", "\n$N�ѹ���������һ�£�˫��һ���ַ���������\n\n");
	set("comeout_message", "��$d���ɶ�ȥ��\n");
	set("comein_message", "���˹�����\n");
	set("fleeout_message", "һ����������$d���ɶ�ȥ��\n");
	set("fleein_message", "�����ط��˹��������ص��ڰ���д���������\n");
}

void setup_bird(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

	my["unit"] = "ֻ";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random(20) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(10) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random(10) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random(20) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(50) + 5;
	if( undefinedp(my["dex"]) ) my["dex"] = random(60) + 5;
	if( undefinedp(my["kar"]) ) my["kar"] = random(20) + 5;

	if( undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 3 ) my["max_jing"] = 30;
		else if( my["age"] <= 10 ) my["max_jing"] = 30 + (my["age"] - 3) * 10;
		else if( my["age"] <= 30 ) my["max_jing"] = 100 + (my["age"] - 10) * 3;
		else my["max_jing"] = 160 + (my["age"] - 30);
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 5 ) my["max_qi"] = 30;
		else if( my["age"] <= 20 ) my["max_qi"] = 30 + (my["age"] - 5) * 15;
		else my["max_qi"] = 255 + (my["age"] - 20) * 5;
	}
	if( undefinedp(my["max_jingli"]) ) {
		if( my["age"] <= 5 ) my["max_jingli"] = 20;
		else if( my["age"] <= 20 ) my["max_jingli"] = 20 + (my["age"] - 5) * 20;
		else my["max_jingli"] = 320 + (my["age"] - 20) * 5;
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 5)* 1000);

	if( ob->query("subrace") == "����" )
	{
		set("dead_message", "\n$N����һ�����������У��Ե��ڵ������ˡ�\n\n");
		set("unconcious_message", "\n$N����һ���Ե��ڵأ����˹�ȥ��\n\n");
		set("revive_message", "\n$N�ѹ���������һ�£�˫�������˼���վ��������\n\n");
		set("comeout_message", "��$d������ȥ��\n");
		set("comein_message", "���˹�����\n");
		set("fleeout_message", "һ����������$d������ȥ��\n");
		set("fleein_message", "ҡҡ�ڰڵ����˹�����\n");
	}
}

mapping query_action(object me)
{
	return combat_action[random(sizeof(combat_action))];
}


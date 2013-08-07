// insect.c ����
// Last Modified by winder on Aug. 1 2002

#ifndef __INSECT__
#define __INSECT__

// A normal insect is at least 1 g weight
#define BASE_WEIGHT 1
#endif

inherit F_DBASE;

mapping *combat_action_crawl = ({
([
	"action":	"$N������������$n��$l�ݺݵ�һҧ",
	"damage":	30,
	"damage_type":	"ҧ��",
]),
([
	"action":	"$NԾ�����͵���$n��$l����һ��",
	"damage":	10,
	"damage_type":	"����",
]),
([
	"action":	"$N��ת����β�ͼ��׼$n��$lһ��",
	"damage":	20,
	"damage_type":	"����",
]),
});

mapping *combat_action_fly = ({
([
	"action":	"$N�ɹ���������$n��$l�ݺݵ�һҧ",
	"damage":	30,
	"damage_type":	"ҧ��",
]),
([
	"action":	"$N�������͵���$n��$l����һ��",
	"damage":	10,
	"damage_type":	"����",
]),
([
	"action":	"$N��ת����β�ͼ��׼$n��$lһ��",
	"damage":	20,
	"damage_type":	"����",
]),
});

void create()
{
	seteuid(getuid());
	set("attitude", "heroism");
}

void setup_insect(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	my["unit"] = "ֻ";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random( 5) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random( 5) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random( 5) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random( 5) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(10) + 5;
	if( undefinedp(my["dex"]) ) my["dex"] = random(15) + 5;
	if( undefinedp(my["kar"]) ) my["kar"] = random(10) + 5;

	if( undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 5 ) my["max_jing"] = my["age"] * 5;
		else my["max_jing"] = 25;
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 5 ) my["max_qi"] = my["age"] * 5;
		else my["max_qi"] = 25;
	}
	if( undefinedp(my["max_jingli"]) ) {
		if( my["age"] <= 5 ) my["max_jingli"] = my["age"] * 5;
		else my["max_jingli"] = 25;
	}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 5)* 100);

	if( ob->query("subrace") == "����" )
	{
		set("dead_message", "\n$N�Ľų���ط��˹��������ˡ�\n\n");
		set("unconcious_message", "\n$N�Ľų���ط��˹����������ˡ�\n\n");
		set("revive_message", "\n$Nһ�·����������ݵ��Ĵ�����������\n\n");
		set("comeout_message", "৵�Ծ��ݴԣ���$d���˳�ȥ��\n");
		set("comein_message", "���˹�����\n");
		set("fleeout_message", "৵�Ծ��ݴԣ���$d���˳�ȥ��\n");
		set("fleein_message", "�������˹�����������Щ���͡�\n");

		set("limbs", ({"ͷ��",	"����",	"����", "����", "ǰ��",	"����", "β��"}) );
	}

	if( ob->query("subrace") == "�ɳ�" )
	{
		set("dead_message", "\n$N���ڵ��ϣ������˼��¾����ˡ�\n\n");
		set("unconcious_message", "\n$N�˵ĵ��ڵ��ϣ����˹�ȥ��\n\n");
		set("revive_message", "\n$N�ſ����������һ�£��ַ���������\n\n");
		set("comeout_message", "�����˵ؽ�����$d���˳�ȥ��\n");
		set("comein_message", "���˵ؽ��ŷ��˹�����\n");
		set("fleeout_message", "���˵ؽ�����$d���˳�ȥ��\n");
		set("fleein_message", "�������˹�����������Щ���͡�\n");

		set("limbs", ({"ͷ��",	"����",	"����",	"���", "ǰ��",	"����", "β��"}) );
	}
}

mapping query_action(object me)
{
	if( me->query("subrace") == "����" )
		return combat_action_crawl[random(sizeof(combat_action_crawl))];
	if( me->query("subrace") == "�ɳ�" )
		return combat_action_fly[random(sizeof(combat_action_fly))];
}

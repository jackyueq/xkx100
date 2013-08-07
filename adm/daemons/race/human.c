// /adm/daemons/race/human.c
// From ES2
// Modified by Xiang@XKX
// Modified by Zeratul Jan 6 2001
// Last Modified by winder on Aug. 1 2002

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([	"action":	"$N��ȭ����$n��$l",
		"damage_type":	"����",
	]),
	([	"action":	"$N��$n��$lһץ",
		"damage_type":	"ץ��",
	]),
	([	"action":	"$N��$n��$l�ݺݵ�����һ��",
		"damage_type":	"����",
	]),
	([	"action":	"$N����ȭͷ��$n��$l��ȥ",
		"damage_type":	"����",
	]),
	([	"action":	"$N��׼$n��$l�����ӳ�һȭ",
		"damage_type":	"����",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "λ");
	set("gender", "����");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���",
		"�ұ�", "����", "����", "����", "����", "����", "С��",
		"����", "����", "����", "���", "�ҽ�", "���", "�Ҷ�"
	}) );

	set("dead_message", "\n$N���ڵ��ϣ������˼��¾����ˡ�\n\n");
	set("unconcious_message", "\n$N����һ�����ȣ����ڵ��ϻ��˹�ȥ��\n\n");
	set("revive_message", "\n$N���������۾��������˹�����\n\n");
}

void setup_human(object ob)
{
	mapping my;
	int xism_age, i;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

	if( undefinedp(my["age"]) ) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 80 - my["str"] - my["con"] - my["dex"];
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);
	if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);
	if (undefinedp(my["sta"]) || my["sta"]==0) my["sta"] = 10 + random(21);
	if (undefinedp(my["cps"]) || my["cps"]==0) my["cps"] = 10 + random(21);
	if (undefinedp(my["cor"]) || my["cor"]==0) my["cor"] = 10 + random(21);

	if (undefinedp(my["max_tili"])) my["max_tili"] = my["sta"] * 5;
	if( userp(ob) || undefinedp(my["max_jing"]) || my["max_jing"]<1 )
	{
		if( my["age"] <= 14 ) my["max_jing"] = 100;
		else if( my["age"] <= 30 ) my["max_jing"] = 100 + (my["age"] - 14) * my["int"];
		else my["max_jing"] = my["int"] * 16 + 100;

		// Modified by zeratul Jan 6 2001
//		if( my["age"] > 60 ) my["max_jing"] -= (my["age"] - 60) * 5 ;
		if ( my["age"] > 60 )
		{
			i = my["age"] - 60;
			i = i * ( i + 1 ) / 2;
			my["max_jing"] -= i;
		}

		// ���ұ�����
		if(my["age"] > 60 && (int)ob->query_skill("taoism", 1) >= 120)
		{
			// Modified by zeratul Jan 6 2001
//			my["max_jing"] += (my["age"] - 60) * 5;
			my["max_jing"] += i;
		}

		// ���������������ǰ������������󳤾�
		if((xism_age=(int)ob->query_skill("buddhism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("hunyuan-yiqi", 1)/10);
		}

		// �����������
		if((xism_age=(int)ob->query_skill("ziyunyin", 1)) > 39) 
		{
			xism_age = xism_age/2;
			xism_age -= 14;
			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("zixia-shengong", 1) / 20);
		}

		if( my["max_jingli"] > 0 ) my["max_jing"] += my["max_jingli"] / 4;
		// Modified by zeratul Jan 6 2001
		if ( my["max_jing"] < 1 )
			my["max_jing"] = 1;		 
	}
	if( userp(ob) || undefinedp(my["max_qi"]) || my["max_qi"] < 1 )
	{
		if( my["age"] <= 14 ) my["max_qi"] = 100;
		else if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["age"] - 14) * my["con"];
		else my["max_qi"] = my["con"] * 16 + 100;

		// Modified by zeratul Jan 6 2001
//		if( my["age"] > 60 ) my["max_qi"] -= (my["age"] - 60) * 5;
		if ( my["age"] > 60 )
		{
			i = my["age"] - 60;
			i = i * ( i + 1 ) * 2;
			my["max_qi"] -= i;
		}

		// ��ұ�����
		if(my["age"] > 60 && (int)ob->query_skill("buddhism", 1) >= 120)
		{
			// Modified by zeratul Jan 6 2001
//			my["max_qi"] += (my["age"] - 60) * 5;
			my["max_qi"] += i;
		}

		// ������һ��������������ǰ���������������
		if((xism_age=(int)ob->query_skill("taoism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("taiji-shengong", 1)/10);
		}
		// ����ȫ����������������ǰ���������������
		if((xism_age=(int)ob->query_skill("taoism", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("xiantian-qigong", 1)/10);
		}
		// ������������
		if((xism_age=(int)ob->query_skill("zhengqijue", 1)) > 39) 
		{
			xism_age = xism_age/2;
			xism_age -= 14;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("zixia-shengong", 1) / 20);
		}
		// ����������������ǰ���������������
		if((xism_age=(int)ob->query_skill("poison", 1)) > 39)
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("huagong-dafa", 1)/10);
		}

		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"] / 4;

		// Modified by zeratul Jan 6 2001
		if ( my["max_qi"] < 1 )
			my["max_qi"] = 1;		
	}

	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)*2000);

}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

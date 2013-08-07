// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

//string *gift_ranking = ({"����֮ѡ","�µ�", "����", "�е�", "����", "�ϵ�",
//	"����֮ѡ"});

string bar_string = "��������������������������������������������������";
string blank_string = "��������������������������������������������������";
//string bar_string = "�������������������������������������������������";
//string blank_string= "�񡪡���������������������������������������������";

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type, char_type;
	object weapon;
	int attack_points, dodge_points, parry_points;

	seteuid(getuid(me));


	if(!arg || arg == me->query("id")) ob = me;
	else
	{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if(!wizardp(me))
		{
			if(!ob) return notify_fail("ֻ�в쿴���״̬��\n");
			if(!ob->query("parents"))
				return notify_fail("��ʦ���ܲ쿴����״̬��\n");
			else
				if(member_array(me->query("id"),ob->query("parents"))<=-1)
					return notify_fail("ֻ�е����ܲ쿴������״̬��\n");
		}
		else if (!ob)
			return notify_fail("���˲����ߣ�����sc�鿴���ݡ�\n");
	}


	my = ob->query_entire_dbase();

	line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
	switch (ob->query("character"))
	{
		case "1" : char_type = "ð��"; break;
		case "2" : char_type = "����"; break;
		case "3" : char_type = "����"; break;
		case "4" : char_type = "���"; break;
		case "5" : char_type = "����"; break;
		default  : char_type = "��ͨ"; break;
	}
	if (userp(ob))
		line += sprintf(" ����һ%s%s��%s�����Ը�%s��%s%s��%s����\n",
		ob->query("unit"),
		chinese_number((int)(ob->query("mud_age")/86400)+14), 
		chinese_number((ob->query("mud_age")%86400)/7200 + 1 ), 
		char_type,
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
	else
		line += sprintf(" ����һ%s%s���Ը�%s��%s%s��%s����\n",
		ob->query("unit"),
		chinese_number(ob->query("age")), 
		char_type,
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );

	line += sprintf(
	" ����[%d/%s]  ����[%d/%s]  ����[%d/%s]  ��[%d/%s]  ����[%d/%s]\n",
		my["str"], display_attr(my["str"], ob->query_str()),
		my["int"], display_attr(my["int"], ob->query_int()),
		my["con"], display_attr(my["con"], ob->query_con()),
		my["dex"], display_attr(my["dex"], ob->query_dex()),
		my["sta"], display_attr(my["sta"], ob->query_sta()));
	if( wizardp(me) || (int)ob->query("age") >= 18 )
	{
		line += sprintf(
	" ����[%d/%s]  ��Ե[%d/%s]  ��ʶ[%d/%s]  ����[%d/%s]  ��ò[%d/%s]\n",
		my["spi"], display_attr(my["spi"], ob->query_spi()),
		my["kar"], display_attr(my["kar"], ob->query_kar()),
		my["cor"], display_attr(my["cor"], ob->query_cor()),
		my["cps"], display_attr(my["cps"], ob->query_cps()),
		my["per"], display_attr(my["per"], ob->query_per()));
	}
	line += sprintf("\n");
	if (userp(ob))
	{
		if( mapp(my["family"]) )
		{
			if( my["family"]["master_name"] )
				line = sprintf("%s ���ʦ���� %s��",
					line, my["family"]["master_name"] );
		} else line = sprintf("%s �㻹û��ʦ����", line );
		if (!ob->query("couple/couple_name"))
		{
			if (ob->query("gender")=="Ů��")
				if (ob->query("age")<20)
					line += "        �����ڴ��ֹ��С�\n";
				else line += "        �����ڻ��Ǹ�������塣\n";
			else line += "        �㻹�Ǹ������\n";
		} else line += " ��İ����� "+ob->query("couple/couple_name")+"��\n";
		if ((int)ob->query("balance") > 0)
			line += " ��" + MONEY_D->money_str((int)ob->query("balance")) + "��\n\n";
		else line += " �����ڻ�û�д�\n\n";
	}

	line += " <��>  " + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], GRN) + "\n";
	line += " <��>  " + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + "\n";
//	line += " <��>  " + tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], HIB) + "\n";

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob,skill_type,SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob,skill_type,SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob,"dodge",SKILL_USAGE_DEFENSE);

	if (wizardp(me))
	{
		line += sprintf("\n ս�������� " HIW "%8d" NOR "\t\tս�������� " HIW "%8d\n" NOR,
		attack_points/100 + 1, (dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1,);
		line += sprintf(" ս���˺��� " HIW "%8d" NOR "\t\tս�������� " HIW "%8d\n\n" NOR,
		ob->query_temp("apply/damage"), ob->query_temp("apply/armor"));
	}
	else line += "\n";

	line += " ʳ�" + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
	line += " ��ˮ��" + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n";

	line += sprintf("\n �㵽ĿǰΪֹ�ܹ�ɱ�� %d ���ˣ������� %d ����������ҡ�\n",
		my["MKS"] + my["PKS"], my["PKS"]);
	line += sprintf(" �㵽ĿǰΪֹ�ܹ����� %d ���ˣ������� %d ���Ƿ�����������\n\n",
		my["dietimes"] + my["normal_die"], my["dietimes"]);

	if (ob->query("shen") >=0)
		line += sprintf(" ��    ���� "RED"%8d\t"NOR,ob->query("shen") );
	else
		line += sprintf(" ��    ���� "RED"%8d\t"NOR,ob->query("shen") );

	line += sprintf(" Ǳ    �ܣ� "HIY"%3d (%3d%%)\t" NOR,
		(int)ob->query("potential") - (int)ob->query("learned_points"),
		(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential")) );
	line += sprintf(" ʵս���飺 "HIM"%8d\n"NOR, ob->query("combat_exp") );
	line += sprintf(" ��    ���� "HIC"%8d\t"NOR, ob->query("meili") );
	line += sprintf(" ���������� "HIC"%8d\t"NOR, ob->query("score") );
	line += sprintf(" ���������� "HIC"%8d\n"NOR, ob->query("weiwang") );

	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
	else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*25/max)*2-1] + ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
	);
	return 1;
}

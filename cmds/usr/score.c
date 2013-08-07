// Last modified by winder 2003.9.2
// score.c

#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
string display_attr(int gift, int value);
string bar_string = "��������������������������������";
string blank_string = "��������������������������������";
string none_string = "                                  ";
string tribar_graph(int val, int eff, int max, string color);
string fill_blank(string type, int num);
string remove_ansi(string str)
{
	int i;
	string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT, HIR, HIG, HIY, HIB, HIM, HIC, HIW, HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT, BBLK, BRED, BYEL, BBLU, BMAG, BCYN, NOR, BOLD });

	if( !str || !stringp(str) ) return 0;
	i = sizeof(color);
	while( i-- ) {
		str = replace_string(str, color[i], "");
	}
	return str;
}
string fill_blank(string type, int num)
{
	string bak;
	int i, j;

	bak="";
	i=strlen(type);
	for (j=0; j<num-i; j++ ) bak+=" ";
	return bak;
}
int check_cc(string str);
string value_string(int value1,int value)
{
	string str;
	if(value1)
	{
		str=((int)(value1/10000)?chinese_number(value1/10000)+"��":"")+chinese_number(value1%10000)+"��";
		if(value<1) return str+"���ƽ�";
		else
			if(value<100) return str+"���ƽ�"+chinese_number(value)+"��Ǯ";
			else
				if(value<10000) return str+"���ƽ�"+chinese_number(value/100)+"������"+(value%100?"��"+chinese_number(value%100)+"��Ǯ":"");
				else return str+chinese_number(value/10000 )+"���ƽ�"+((value%10000)/100 ? chinese_number((value%10000)/100)+"������":"")+((value%10000)%100 ? "��"+chinese_number((value%10000)%100)+"��Ǯ":"");
	}
	else
	{
		if(value<1) return "";
		else
			if(value<100) return chinese_number(value)+"��Ǯ";
			else
				if(value<10000) return chinese_number(value/100)+"������"+(value%100 ? "��"+chinese_number(value%100)+"��Ǯ":"");
				else return chinese_number(value/10000)+"���ƽ�"+((value%10000)/100 ? chinese_number((value%10000)/100)+"������":"")+((value%10000)%100 ? "��"+chinese_number((value%10000)%100)+"��Ǯ":"");
	}
}
string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else
		if( value < gift ) return sprintf( CYN "%3d" NOR, value );
		else return sprintf("%3d", value);
}
string tribar_graph(int val, int eff, int max, string color)
{
	return color+bar_string[0..(val*16/max)*2-1]+((eff>val) ? blank_string[(val*16/max)*2..(eff*16/max)*2-1]:"")+((max>eff) ? none_string[(eff*16/max)*2..31]:"")+NOR;
}
int check_cc(string str)
{
	int i, nn_len;
	for (nn_len=0,i=0;i<strlen(str);i++)
	{
		if (str[i]==27)
		{
			for (;str[i]!=109;i++)
			{
				nn_len++;
			}
			nn_len++;
		}
	}
	return nn_len;
}


void create() { seteuid(ROOT_UID); }
int main(object me, string arg)
{
	string line,skill_type,master,couple,all_title,char_type;
	mapping my,pmap;
	object ob, weapon;
	int i,cc_len,attack_points,dodge_points,parry_points,balance,balance1,balance2,flag;

	seteuid(getuid());
	if(!arg) ob = me;
	else
		if (wizardp(me))
		{
			ob = present(arg, environment(me));
			if (!ob) ob = find_player(arg);
			if (!ob) ob = find_living(arg);
			if (!ob)
			{
				flag = 1;
				if (!objectp(ob=NPC_D->create_player(arg)))
					return notify_fail("û�������ҡ�\n");
			}
			if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
			if( !ob->is_character() || ob->is_corpse() )
				return notify_fail("�㲻����"+ob->query("name") +"��״̬���뿴�ɣ���\n");
		}else
		{ 
			ob = present(arg, environment(me));			
			if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭��״̬��\n");
			if (ob != me && !(ob->query("parents") && member_array(me->query("id"), ob->query("parents"))>=0))
			return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
		}
	balance = (int)ob->query("balance");
	balance1 = (int)ob->query("more_balance");
	balance2 = (int)ob->query("trade_balance");
	my = ob->query_entire_dbase();

	pmap = me->query_skill_prepare();
	if(objectp(weapon = me->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		if(sizeof(pmap)==0) skill_type="unarmed";
		else
			if(sizeof(pmap)==1) skill_type=(keys(pmap))[0];
			else
				if(sizeof(pmap)==2)
				{
					if((keys(pmap))[0]>=(keys(pmap))[1])
						skill_type = (keys(pmap))[0];
					else skill_type=(keys(pmap))[1];
				}
	attack_points = COMBAT_D->skill_power(ob,skill_type,SKILL_USAGE_ATTACK);
// ��combatd.cΪ��׼��parry point
  if (ob->query_temp("weapon"))
  parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
  else
  parry_points = COMBAT_D->skill_power(ob, "unarmed", SKILL_USAGE_DEFENSE);
//	parry_points = COMBAT_D->skill_power(ob,skill_type,SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob,"dodge",SKILL_USAGE_DEFENSE);
	master = ob->query("family")?my["family"]["master_name"]:"Ŀǰ��û��";
	couple = mapp(my["couple"])?(my["couple"]["have_couple"]?my["couple"]["couple_name"]:"Ŀǰ��û��"):"Ŀǰ��û��";

	line = "\n������������"+HIR"�����˵�����"NOR"���������� "+MAG"\t\t"+"    �츳"NOR"\n";

	line += sprintf("%-32s��%s\n","��",CYN"    ���ԣ�["NOR+display_attr(my["int"], my["int"])+"/"+display_attr(my["int"], ob->query_int())+CYN"]     ���ǣ�["NOR+display_attr(my["con"], my["con"])+"/"+display_attr(my["con"], ob->query_con())+CYN"] "NOR);

	line += sprintf("��ͷ�����Σ���  %s%s��%s\n", RANK_D->query_rank(ob), fill_blank(remove_ansi(RANK_D->query_rank(ob)), 16), CYN"    ������["NOR+display_attr(my["str"], my["str"])+"/"+display_attr(my["str"], ob->query_str())+CYN"]     ����["NOR+display_attr(my["dex"], my["dex"])+"/"+display_attr(my["dex"], ob->query_dex())+CYN"]"NOR);

	if( wizardp(me) || (int)ob->query("age") >= 18 )
	{
		line += sprintf("%s%-16s��%s\n", "����������:     ",ob->name(),CYN"    ������["NOR+display_attr(my["sta"], my["sta"])+"/"+display_attr(my["sta"], ob->query_sta())+CYN"]     ��ò��["NOR+display_attr(my["per"], my["per"])+"/"+display_attr(my["per"], ob->query_per())+CYN"]"NOR);
		line += sprintf("%s%-16s��%s\n", "��Ӣ������:     ",ob->query("id"),CYN"    ���ԣ�["NOR+display_attr(my["spi"], my["spi"])+"/"+display_attr(my["spi"], ob->query_spi())+CYN"]     ��Ե��["NOR+display_attr(my["kar"], my["kar"])+"/"+display_attr(my["kar"], ob->query_kar())+CYN"]"NOR);
		line += sprintf("%s%-16s��%s\n", "����    ��:     ",ob->query("gender"),CYN"    ��ʶ��["NOR+display_attr(my["cor"], my["cor"])+"/"+display_attr(my["cor"], ob->query_cor())+CYN"]     ������["NOR+display_attr(my["cps"], my["cps"])+"/"+display_attr(my["cps"], ob->query_cps())+CYN"]"NOR);
	}
	else
	{
		line += sprintf("%s%-16s��%s\n", "����������:     ",ob->name(),CYN"    ������["NOR"???/???"CYN"]     ��ò��["NOR+"???/???"CYN"]"NOR);
		line += sprintf("%s%-16s��%s\n", "��Ӣ������:     ",ob->query("id"),CYN"    ���ԣ�["NOR"???/???"CYN"]     ��Ե��["NOR+"???/???"CYN"]"NOR);
		line += sprintf("%s%-16s��%s\n", "����    ��:     ",ob->query("gender"),CYN"    ��ʶ��["NOR"???/???"CYN"]     ������["NOR+"???/???"CYN"]"NOR);
	}

	switch (ob->query("character"))
	{
		case "1" : char_type = "ð��"; break;
		case "2" : char_type = "����"; break;
		case "3" : char_type = "����"; break;
		case "4" : char_type = "���"; break;
		case "5" : char_type = "����"; break;
		default  : char_type = "��ͨ"; break;
	}

	line += sprintf("%s%-16s%39s\n","�������Ը�:     ",char_type,"��������������������������������������������" );
	if( ob->query("title") )
	{ 
		if( ob->query("degree") )
		{  
			all_title = ob->query("degree")+ob->query("title");
			line += sprintf("���ơ���ν��  ��%s%s��\n", all_title, fill_blank(remove_ansi(all_title), 58),);
		}
		else
		{
			line += sprintf("���ơ���ν��  ��%s%s��\n", ob->query("title"), fill_blank(remove_ansi(ob->query("title")), 58),);
		}
	}

	if( ob->query("nickname") )
	{
		line += sprintf("%s%-58s", "����ı��:     ",ob->query("nickname"));
		for (i=0,cc_len=check_cc(ob->query("nickname"));i<cc_len;i++)
		{
			line += sprintf("%s"," ");
		}
		line += sprintf("%s","��\n");
	}
	if( ob->query("born") )
	{ 	
		line += sprintf("����ļ��磺  ��%s%26s%-28s��\n", ob->query("born/hometown"), "���"+(ob->query("gender")=="Ů��"?"�Ϲ�":"����")+"�� ",couple );
	}

	if (base_name(ob)==USER_OB)
		line += sprintf("%s%-19s%s%-28s��\n","���ꡡ���䣺    ",chinese_number(ob->query("age"))+"��"+chinese_number((ob->query("mud_age")-(ob->query("age")-ob->query("age_modify")-14)*86400)/7200+1)+"��","��������� ",CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60) ));
	else 
		line += sprintf("%s%-19s%s%-28s��\n","���ꡡ���䣺    ",chinese_number(ob->query("age"))+"��","��������� ",CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60)));

	line += sprintf("%s%-19s%s%-26d  ��\n", "�����ʦ����    ",master,"ʦ���ҳϣ� ",ob->query("family/fealty"));

	if(ob->query("balance") || ob->query("balance1"))
	{
		line += sprintf("%12s%-58s","��Ǯׯ��    ",value_string(balance1,balance));
		for (i=0,cc_len=check_cc(value_string(balance1,balance));i<cc_len;i++)
		{
			line += sprintf("%s"," ");
		}
		line += sprintf("%s","��\n");
	}
	if(ob->query("trade_balance"))
	{
		line += sprintf("%12s%-58s","����ҵ���ʣ�    ",value_string(0,balance2));
		for (i=0,cc_len=check_cc(value_string(0,balance2));i<cc_len;i++)
		{
			line += sprintf("%s"," ");
		}
		line += sprintf("%s","��\n");
	}

	if (ob->is_character())
	{
		line += sprintf("��ɱ��������    "HIR"%-7d"NOR" ��ң�    "HIY"%-6d"NOR" ���գ�    "HIY"%-6d"NOR" С����    "HIY"%-6d"NOR"��\n", my["PKS"]+my["MKS"], my["PKS"], my["WKS"], my["WKS1"]);

		line += sprintf("��    ͬ�ţ�    "HIY"%-7d"NOR" ʦ����    "HIY"%-6d"NOR" ͬ�    "HIY"%-6d"NOR" ���ϣ�    "HIY"%-6d"NOR"��\n", my["IKS"], my["IKS1"], my["BKS"], my["BKS1"]);

		line += sprintf("����ɱ�ܼƣ�    "HIR"%-7d"NOR" ������    "HIR"%-6d"NOR" ��ʦ��    "HIY"%-6d"NOR" ������    "HIY"%-6d"NOR"��\n", my["dietimes"]+my["normal_die"], my["dietimes"], my["betrayer"], my["expell"]);
	}
	if (ob->query("last_die_msg"))
		line += sprintf("���������    %-58s��\n",ob->query("last_die_msg"));

		line += sprintf("%s"HIW"%-19d"NOR"%s%-46s��\n", "����    �飺    ", ob->query("combat_exp"), "ʳ� ",tribar_graph(my["food"], (ob->query("str")+10)*10,(ob->query("str")+10)*10,YEL));
		line += sprintf("%s"HIC"%-19d"NOR"%s%-46s��\n", "��Ǳ    �ܣ�    ", ob->query("potential")-ob->query("learned_points"), "��ˮ�� ", tribar_graph(my["water"], (ob->query("str")+10)*10, (ob->query("str")+10)*10,CYN));

if(ob->query("shen") >= 0)
		line += sprintf("%s"HIR"%-19d"NOR"%s%-46s��\n", "����    ����    ", ob->query("shen"), "<��>�� ",tribar_graph(my["jing"], my["eff_jing"], my["max_jing"],GRN));
	else
		line += sprintf("%s"HIG"%-19d"NOR"%s%-46s��\n", "����    ����    ", ob->query("shen"), "<��>�� ",tribar_graph(my["jing"], my["eff_jing"], my["max_jing"],GRN));
	line += sprintf("%s"HIC"%-19d"NOR"%s%-45s��\n", "������������    ", ob->query("score"), "<��>�� ", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR));
	line += sprintf("%s%-19d%s%-25d��\n","������������    ", my["weiwang"], "����������    ", my["meili"]);

	if (wizardp(me))
	{
		line += sprintf("���� �� ����    "HIR"%-18d"NOR" ����������    "HIR"%-25d"NOR"��\n", attack_points/100+1, dodge_points/100+1);
		line += sprintf("�������˺���    "HIY"%-18d"NOR" �м�������    "HIY"%-25d"NOR"��\n", ob->query_temp("apply/damage"),parry_points/100+1  );
		line += sprintf("�������˺���    "HIG"%-18d"NOR" ����������    "HIG"%-25d"NOR"��\n", ob->query_temp("apply/unarmed_damage"), ob->query_temp("apply/armor"));
		line += sprintf("�����ӹ�����    "HIG"%-18d"NOR" �������㣺    "HIG"%-25d"NOR"��\n", ob->query_temp("apply/attack"), ob->query_temp("apply/dodge"));
	}

	line +="����������������������������������������������������������������������������\n"NOR;


  line += sprintf(WHT+" %s��"+HIG+CHINESE_MUD_NAME+NOR+"�����Ϸʱ����:"+BLINK+HIY"%s \n"+NOR,ob==me?"��":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age")));
         
  line+=sprintf("\n");
  line+=sprintf("%s", flag?"�����Ŀǰ�������ϡ�\n":"");
  write(line);
  if (flag)
		destruct(ob);
	return 1;
}


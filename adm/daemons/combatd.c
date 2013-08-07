// /adm/daemons/combatd.c

// Modified by Zeratul Jan 5 2001
// Modified by Constant Jan 16 2001

#pragma optimize all

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <command.h>
#include </quest/quest.h>

inherit F_DBASE;
#define SETDISPLAY(x,y) (ESC+"["+x+";"+y+"f")
#define DELLINE ESC+"[K"

object *player;
int userno;

string *guard_msg = ({
	CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
	CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
	CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
	CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
	CYN "$N�������ƶ��ŽŲ����Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
	HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
	HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
	HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
	HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
	HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
	HIW "$N����$n��У�����֪����Ķ�����������������ɣ���\n" NOR,
	HIW "$N�ȵ�����$n�����У���\n" NOR,});

string *winner_msg = ({
	CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR,
	CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR,
	CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
	CYN "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n\n" NOR,
	CYN "\n$n������˼�����˵�����ⳡ�����������ˣ��»ؿ�����ô��ʰ�㣡\n\n" NOR,
	CYN "\n$n���һ�ݣ��޺޵�˵�������ӱ���ʮ�겻����\n\n" NOR,
	CYN "\n$n��ɫһ����˵�����������ˣ��͵���������ɣ�\n\n" NOR,
	CYN "\n$n������Ц���е������������ã��������ã���һ���������������\n\n" NOR,
	CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
	CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
	CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

void create()
{
	seteuid(getuid());
	set("name", "ս������");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "��� " + damage + " ��" + type + "��\n";

	if( damage == 0 ) return "���û������κ��˺���\n";

	switch( type ) {
	case "����":
	case "����":
	case "����":
		if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
		else if( damage < 20 ) return "�����$p$l����һ��ϸ��Ѫ�ۡ�\n";
		else if( damage < 40 ) return "������͡�һ������һ���˿ڣ�\n";
		else if( damage < 80 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
		else if( damage < 160 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
		else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
		break;
	case "����":
		if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
		else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
		else if( damage < 40 ) return "������ۡ���һ��������$n$l������\n";
		else if( damage < 80 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
		else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ�������Ѫ������\n";
		else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
		break;
	case "����":
	case "����":
		if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
		else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
		else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
		else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
		else if( damage < 120 ) return "������项��һ����$n����������\n";
		else if( damage < 160 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
		else if( damage < 240 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
		else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
		break;
	case "����":
		if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
		else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
		else if( damage < 40 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
		else if( damage < 80 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
		else if( damage < 120 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
		else if( damage < 160 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
		else if( damage < 240 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
		else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
		break;
	case "ץ��":
		if( damage < 10 ) return "���ֻ�������ץ��$p��Ƥ�⡣\n";
		else if( damage < 20 ) return "�����$p$lץ��һ��ϸ��Ѫ�ۡ�\n";
		else if( damage < 40 ) return "���ץ��һ��������Ѫ�ڣ�\n";
		else if( damage < 80 ) return "���ץ��һ��Ѫ���ܵ��˿ڣ�\n";
		else if( damage < 160 ) return "���ץ��һ���ֳ�������˿ڣ�$N����մ������Ѫ��\n";
		else return "���ֻ����$nһ���Һ���$p$l��ץ��һ������ǵĿ����˿ڣ���\n";
		break;
	default:
		if( !type ) type = "�˺�";
		if( damage < 10 ) str = "���ֻ����ǿ���һ����΢";
		else if( damage < 20 ) str = "��������΢��";
		else if( damage < 30 ) str = "������һ��";
		else if( damage < 50 ) str = "������һ������";
		else if( damage < 80 ) str = "��������Ϊ���ص�";
		else if( damage < 120 ) str = "�������൱���ص�";
		else if( damage < 170 ) str = "������ʮ�����ص�";
		else if( damage < 230 ) str = "�����ɼ������ص�";
		else str = "�����ɷǳ����µ�����";
		return str + type + "��\n";
	}
}

string eff_status_msg(int ratio)
{
	if (ratio==100) return HIG"��������Ѫ��ӯ����û�����ˡ�"NOR;
	if (ratio > 95) return HIG"�ƺ����˵����ˣ����������������������"NOR;
	if (ratio > 90) return HIY"�������������˵����ˡ�"NOR;
	if (ratio > 80) return HIY"���˼����ˣ������ƺ��������¡�"NOR;
	if (ratio > 60) return HIY"���˲��ᣬ������״������̫�á�"NOR;
	if (ratio > 40) return HIR"��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
	if (ratio > 30) return HIR"�Ѿ��˺����ۣ���������֧���Ų�����ȥ��"NOR;
	if (ratio > 20) return HIR"�����൱�ص��ˣ�ֻ�»�������Σ�ա�"NOR;
	if (ratio > 10) return RED"����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�"NOR;
	if (ratio > 5 ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�"NOR;
	return RED"���˹��أ��Ѿ�������в�����ʱ�����ܶ�����"NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG"����������������һ��Ҳ���ۡ�"NOR;
	if( ratio > 95 ) return HIG"�ƺ���Щƣ����������Ȼʮ���л�����"NOR;
	if( ratio > 90 ) return HIY"������������Щ���ˡ�"NOR;
	if( ratio > 80 ) return HIY"�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�"NOR;
	if( ratio > 60 ) return HIY"�������꣬������״������̫�á�"NOR;
	if( ratio > 40 ) return HIR"�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�"NOR;
	if( ratio > 30 ) return HIR"�Ѿ�һ��ͷ�ؽ����ģ������������֧���Ų�����ȥ��"NOR;
	if( ratio > 20 ) return HIR"�������Ѿ����������ˡ�"NOR;
	if( ratio > 10 ) return RED"ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�"NOR;
	return RED"�Ѿ���������״̬����ʱ������ˤ����ȥ��"NOR;
}

varargs void report_status(object ob, int effective)
{
// �����ֳ�ת�� start
	player=users();
// �����ֳ�ת�� end
	if( effective ) 
	{
		message_vision( "( $N" + eff_status_msg(
			(int)ob->query("eff_qi")*100 / (int)ob->query("max_qi"))
			+ " )\n", ob);
// �����ֳ�ת�� start
		if ((string)environment(ob)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "�����")
				tell_object(player[userno], "( " + ob->name() + eff_status_msg((int)ob->query("eff_qi")*100 / (int)ob->query("max_qi"))+" )\n");
// �����ֳ�ת�� end
	}
	else
	{
		message_vision( "( $N" + status_msg(
			(int)ob->query("qi") * 100 / (int)ob->query("max_qi")) 
			+ " )\n", ob);
// �����ֳ�ת�� start
		if ((string)environment(ob)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "�����")
				tell_object(player[userno], "( " + ob->name() + status_msg( (int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) + " )\n");
// �����ֳ�ת�� end
	}
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int status, level, power, dex, str, exp;
	float dpower;
	string dskill;

	if( !living(ob) || ob->query_temp("noliving") ) return 0;

	level = ob->query_skill(skill);
	switch(usage)
	{
		case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level += ob->query_temp("apply/defense");

/* ��ͬ�Ṧ�в�ͬ������������(power_point)��ΧΪ1��1.5֮�䡣�Ͻ����� */
			dskill = ob->query_skill_mapped("dodge");
			if( dskill )
			{
				dpower = SKILL_D(dskill)->power_point(ob);
//				if( dpower >= 1.0 && dpower <= 1.5 )
				  if( dpower < 1.0) dpower = 1.0;
			  	if (dpower > 1.5) dpower = 1.5;
					level = level * dpower;
			}
			break;
	}

	if( !level ) return (int)ob->query("combat_exp") / 2;
/* ��ֹ���������� */
	if (level > 800) level = 800;
	if (level < 1) level = 1;

	str = ob->query_str();
	if (str < 10 ) str = 10;
	if (str > 200 ) str = 200;
	dex = ob->query_dex();
	if (dex < 10 ) dex = 10;
	if (dex > 200 ) dex = 200;
	exp = ob->query("combat_exp");
	power = (level / 6)*level*level;

	if (usage == SKILL_USAGE_ATTACK)
		return (power+exp)/80*(str+ob->query("str"));
	else
		return (power+exp)/80*(dex+ob->query("dex"));
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type,string msg)
{
	mapping my, your, prepare, action;
	string limb, *limbs, result;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int ap, dp, pp;
	int damage, damage_bonus, defense_factor;
	int wounded = 0;

// �����ֳ�ת�� start
	player=users();
// �����ֳ�ת�� end

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();

	//
	// (0) Choose skills.
	//
	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);

	if( objectp(weapon) ) attack_skill = weapon->query("skill_type");
	else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
	else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];

	//
	// (1) Find out what action the offenser will take.
	//
	if (me->query("env/no_fight")) return 0;
	if (!me->query_temp("no_reset_action"))
	me->reset_action();
	else me->delete_temp("no_reset_action");
	action = me->query("actions");
	if( !mapp(action) ) {
		me->reset_action();
		action = me->query("action");
		if( !mapp(action) )
		{
			CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s): bad action = %O", me->name(1), me->query("id"), me->query("actions", 1)));
			return 0;
		}
	}
	result = action["action"];
	if (stringp(msg)) result = msg;
	if (me->query_temp("action_flag") == 0)
		result = "\n" + result + "��\n";
	else result = "\n" + "������"+result + "��\n"; 

	//
	// (2) Prepare AP, DP for checking if hit.
	//
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];

// �Լ��ȳ��У����ֲſ��ܽ�����Ӧ�ķ������߶��� //by qingyun
	result = replace_string( result, "$l", limb );
/* �мܵı��� ������parry.c�� */
	if( victim->query_temp("weapon"))
		result = replace_string( result, "$W", victim->query_temp("weapon")->name() );
	else result = replace_string( result, "$W", "ȭ��" );
	if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "finger" ) 
		result = replace_string( result, "$w", "��ָ" );
	else result = replace_string( result, "$w", "ȭ��" );

//	message_vision(result, me, victim );
	if (!me->query("env/combatd2") && 
	(userp(me) || !victim->query("env/combatd2")))
	message_combatd(result, me, victim );
  result = "";
// ���н��� ����result
	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
// ���ƹ���������, ���⸺����
	if( ap < 1) ap = 1;
	if( ap > 200000000) ap = 200000000;

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( action["dodge"] )
	{
		if( dp > 1000000 )
			dp = dp / 100 * (100 + action["dodge"]);
		else 
			dp = (100 + action["dodge"]) * dp / 100;
	}
// ���ƹ���������, ���⸺����
	if( dp < 1 ) dp = 1;
	if( dp > 200000000) dp = 200000000;
	if( victim->is_busy() ) dp /= 3;

	//
	// (3) Fight!
	//	Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
	//	AP and DP are greater than zero, so we always have chance to hit
	//	or be hit.
	//

// Java �������
//	if( random(100) > dp * 100 / (ap + dp) )
	if( random(ap + dp) < dp && !(victim->query_temp("bixie/cizu")))
// Does the victim dodge this hit?
// ��а�������޷�����
	{
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

		if( dp < ap && (!userp(victim) || !userp(me)) 
		&& random(your["jing"]*100/your["max_jing"]+your["int"]) > 50)
		{
			your["combat_exp"] += 1;
// ���ƻ�����������
			if(victim->query_skill("dodge", 1) < 300)
				victim->improve_skill("dodge", 1);
		}

// This is for NPC only. NPC have chance to get exp when fail to hit.
		if( (ap < dp) && !userp(me) )
		{
			if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
			me->improve_skill(attack_skill, random(my["int"]));
		}
		damage = RESULT_DODGE;
//		if (damage<0) damage=0;
		if( wizardp(me) &&
			(string)me->query("env/combat")=="verbose" ) 
			tell_object(me, sprintf(CYN+victim->name()+"��ܳɹ����������%d \n"NOR, dp));
		if( wizardp(victim) &&
			(string)victim->query("env/combat")=="verbose" ) 
			tell_object(victim, sprintf(CYN+victim->name()+"��ܳɹ����������%d \n"NOR, dp));
	} else
	{
		//
		//	(4) Check if the victim can parry this attack.
		//

		if( victim->query_temp("weapon") )
		{
			pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
			if( !weapon ) pp *= 2;
		} else
		{
			if( weapon ) pp = 0;
			else pp = skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);
		}

		if( victim->is_busy() ) pp /= 3;
		if( action["parry"] )
		{
			if( pp > 1000000 )
				pp = pp / 100 * (100 + action["parry"]);
			else 
				pp = (100 + action["parry"]) * pp / 100;
		}
// ���ƹ���������, ���⸺����
		if( pp < 1 ) pp = 1;
		if( pp > 200000000) pp = 200000000;

		if( random(ap + pp)< pp && !(victim->query_temp("bixie/ciwan")))
// ��а�������޷��м�
		{
			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill || 
				!SKILL_D(parry_skill)->query_parry_msg())
				parry_skill = "parry";
			result += SKILL_D(parry_skill)->query_parry_msg(victim->query_temp("weapon"));

//     if (!weapon && victim->query_temp("weapon")) pp /= 2;
//			if( pp < ap && (!userp(victim) || !userp(me)) 
// ����pp�㽱�� ��ô�ָ��������� ע����һ�� 
			if( dp < ap && (!userp(victim) || !userp(me)) 
			&& random(your["jing"]*100/your["max_jing"] + your["int"]) > 50 )
			{
				your["combat_exp"] += 1;
// ���ƻ�����������
				if(victim->query_skill("parry", 1) < 300)
					victim->improve_skill("parry", 1);
			}
			damage = RESULT_PARRY;
//			if (damage<0) damage=0;
			if( wizardp(me) &&
				(string)me->query("env/combat")=="verbose")
				tell_object(me, sprintf(YEL+victim->name()+"�мܳɹ����м�����%d \n"NOR, pp));
			if( wizardp(victim) &&
				(string)victim->query("env/combat")=="verbose")
				tell_object(victim, sprintf(YEL+victim->name()+"�мܳɹ����м�����%d \n"NOR, pp));
		} else
		{
		//
		//	(5) We hit the victim and the victim failed to parry
		//
			if (objectp(weapon))
				damage = (int)me->query_temp("apply/damage");
			else 
				damage = (int)me->query_temp("apply/unarmed_damage");
			if (damage>300)  damage = 300 + random(damage-300);
			damage = (damage + random(damage)) / 2;
			if( action["damage"] )
//				damage += action["damage"] * damage / 100;
//��������
				damage += action["damage"] * damage / 200;
// Ω�б�����damage��ȭ��������ԶΪ0

// �û��׿��Ե������ֱ������˺�
// ������������ ��damage���� shield���Եó�ǿ
//			damage -= (int)victim->query_temp("apply/armor");
      defense_factor = (int)victim->query_temp("apply/armor");
      if (defense_factor > 300) defense_factor = 300 + random(defense_factor-300);
      defense_factor = (defense_factor + random(defense_factor) )/2;
      damage -= defense_factor;

			if (damage<0) damage=0;
			if( wizardp(me) &&
				(string)me->query("env/combat")=="verbose")
				tell_object(me, sprintf(GRN+"�����˺���%d "NOR, damage));
			if( wizardp(victim) &&
				(string)victim->query("env/combat")=="verbose")
				tell_object(victim, sprintf(GRN+"�����˺���%d "NOR, damage));

			damage_bonus = me->query_str();
			// Let force skill take effect.
			if( my["jiali"] && (my["neili"] > my["jiali"]) )
			{
// �ڹ����е�Ч��
				if(force_skill=me->query_skill_mapped("force")) 
				{ 
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					else if(intp(foo) ) damage_bonus += foo;
				}
			}
// ���ڹ����е�Ч�� add by sega
				if(force_skill=victim->query_skill_mapped("force")) 
				{
					foo = SKILL_D(force_skill)->be_hit_ob(victim,me, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					else if(intp(foo) ) damage_bonus += foo;

				}

			if( action["force"] )
//				damage_bonus+=action["force"]*damage_bonus/100;
// ��������
				damage_bonus+=action["force"]*damage_bonus/200;	
// ���е�Ч��
			if(martial_skill = me->query_skill_mapped(attack_skill))
			{
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
// ������Ч�� add by sega 
			if(martial_skill = victim->query_skill_mapped("parry"))
			{
				foo = SKILL_D(martial_skill)->be_hit_ob(victim,me,damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			// Let weapon or monster have their special damage.
			if( weapon )
			{
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			} else
			{
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
			if( damage_bonus > 0 )
  			damage_bonus = (damage_bonus+random(damage_bonus))/2;
      else
        damage_bonus = 0;
	  	damage += damage_bonus;
      			if( wizardp(me) &&
      				(string)me->query("env/combat")=="verbose")
      				tell_object(me, sprintf(GRN+"�����˺���%d "NOR, damage_bonus));
      			if( wizardp(victim) &&
      				(string)victim->query("env/combat")=="verbose")
      				tell_object(victim, sprintf(GRN+"�����˺���%d "NOR, damage_bonus));
// ����ȭ�Ż��Ǳ����������˺�������
			if( damage < 0 ) damage = 0;

			// Let combat exp take effect
			defense_factor = your["combat_exp"];
			while( random(defense_factor) > my["combat_exp"] )
			{
				damage -= damage / 3;
				defense_factor /= 2;
			}

			//
			//	(6) Inflict the damage.
			//

			if(victim->query_temp("kongming"))
			// ����ȭ�����˺���
			{
				if( damage > 50) damage = damage / 5;
				else damage = 10;
			}
			if( wizardp(me) &&
				(string)me->query("env/combat")=="verbose")
				tell_object(me, sprintf(GRN+"�����������˺���%d \n"NOR, damage));
			if( wizardp(victim) &&
				(string)victim->query("env/combat")=="verbose")
				tell_object(victim, sprintf(GRN+"�����������˺���%d \n"NOR, damage));
// ���е��˵ļ���power_point������
			if(martial_skill = me->query_skill_mapped(attack_skill))
				if( (int)SKILL_D(martial_skill)->power_point(me) > 0)
					damage *= (int)SKILL_D(martial_skill)->power_point(me);
//
// ������ϵ��������������˺���
			damage = victim->receive_damage("qi", damage, me );
			if( wizardp(me) &&
				(string)me->query("env/combat")=="verbose")
				tell_object(me, sprintf(GRN+victim->name()+"���������˺�����%d \n"NOR, damage));
			if( wizardp(victim) &&
				(string)victim->query("env/combat")=="verbose")
				tell_object(victim, sprintf(GRN+victim->name()+"���������˺�����%d \n"NOR, damage));

			if(random(damage)>(int)victim->query_temp("apply/armor")
				&& ((me->is_killing(victim->query("id"))) &&
				((!weapon) && !random(4)|| weapon && !random(2))
			|| ((!weapon) && !random(7) || weapon && !random(4) )) )
			{
// We are sure that damage is greater than victim's armor here.
				victim->receive_wound("qi", damage - (int)victim->query_temp("apply/armor"), me);
				wounded = 1;
			}

			result += damage_msg(damage, action["damage_type"]);

			//
			//	(7) Give experience
			//

			if( !userp(me) || !userp(victim) )
			{
// �޸ĳ�ϵ������������Ǳ�ܵļ��ʡ� Modified by Constant Jan 16 2001
				if( (ap < dp)
				&& (random(my["jing"]*30/my["max_jing"] + my["int"]) > 30) )
				{
					my["combat_exp"] += 1;
					if( my["potential"] - my["learned_points"] < 100000 )
						my["potential"] += 1;
// ���ƻ�����������
					if(me->query_skill(attack_skill, 1) < 300)
						me->improve_skill(attack_skill, 1);
				}
				if(random(your["max_qi"]+your["qi"]) < damage)
				{
					your["combat_exp"] += 1;
					if( your["potential"] - your["learned_points"] < 100000 )
						your["potential"] += 1;
				}
			}
		}
	} 

	result = replace_string( result, "$l", limb );
/* �мܵı��� ������parry.c�� */
	if( victim->query_temp("weapon"))
		result = replace_string( result, "$W", victim->query_temp("weapon")->name() );
	else result = replace_string( result, "$W", "ȭ��" );
	if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "finger" ) 
		result = replace_string( result, "$w", "��ָ" );
	else result = replace_string( result, "$w", "ȭ��" );

	if (!me->query("env/combatd2") && 
	(userp(me) || !victim->query("env/combatd2")))
	message_combatd(result, me, victim );

// �����ֳ�ת�� start
//	message_vision(result, me, victim );
//	result = replace_string(result, "$P", me->name());
//	result = replace_string(result, "$N", me->name());
//	result = replace_string(result, "$n", victim->name());
//	result = replace_string(result, "$p", victim->name());
//	if ((string)environment(me)->query("short") == "��̨")
//	for (userno=0; userno<sizeof(player); userno++)
//		if ((player[userno])->query_temp("view_leitai"))
//			tell_object(player[userno], result);
// �����ֳ�ת�� end

	if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) 
	{
		if( damage > 0 )
			tell_object(me, sprintf( HIG "������%d����ܣ�%d���мܣ�%d���˺�����%d\n" NOR, ap/100, dp/100, pp/100, damage));
		else
			tell_object(me, sprintf( HIG "������%d����ܣ�%d���мܣ�%d\n" NOR, ap/100, dp/100, pp/100));
	}
	if( wizardp(victim) && (string)victim->query("env/combat")=="verbose" ) 
	{
		if( damage > 0 )
			tell_object(victim, sprintf( HIG "������%d����ܣ�%d���мܣ�%d���˺�����%d\n" NOR, ap/100, dp/100, pp/100, damage));
		else
			tell_object(victim, sprintf( HIG "������%d����ܣ�%d���мܣ�%d\n" NOR, ap/100, dp/100, pp/100));
	}
// ��ʾ��Ҿ�������Ѫ
	if( me->query("env/verbose") ) 
	{
		tell_object(me, SAVEC);
		tell_object(me, SETDISPLAY(21,49)+DELLINE);
		tell_object(me, SETDISPLAY(22,49)+DELLINE);
		tell_object(me, SETDISPLAY(23,49)+DELLINE);
		tell_object(me, SETDISPLAY(21,50)+HIY"������������������������������");
		tell_object(me, SETDISPLAY(22,50)+HIY"��");
		tell_object(me, SETDISPLAY(22,52)+HIG"����"HIR+me->query("jing")+"/"+me->query("eff_jing"));
		tell_object(me, SETDISPLAY(22,65)+HIG"����"HIR+me->query("qi")+"/"+me->query("eff_qi"));
		tell_object(me, SETDISPLAY(22,78)+HIY"��");
		tell_object(me, SETDISPLAY(23,50)+HIY"������������������������������"NOR);
		tell_object(me, REST);
	}
	if( damage > 0 ) {
		report_status(victim, wounded);
		if( victim->is_busy() ) victim->interrupt_me(me);
		if( (!me->is_killing(your["id"])) && 
		(!victim->is_killing(my["id"])) &&
		victim->query("qi")*2 <= victim->query("max_qi")) {
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
//			message_combatd( winner_msg[random(sizeof(winner_msg))], me, victim);
// �����ֳ�ת�� start
		result = winner_msg[random(sizeof(winner_msg))];
		result = replace_string(result, "$P", me->name());
		result = replace_string(result, "$N", me->name());
		result = replace_string(result, "$n", victim->name());
		result = replace_string(result, "$p", victim->name());
		if ((string)environment(me)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai") &&
             (string)environment(player[userno])->query("short") == "�����")
				tell_object(player[userno], result);
// �����ֳ�ת�� end
	    return 1;
		}
	}

	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);

	// See if the victim can make a riposte.
	if( attack_type==TYPE_REGULAR && damage < 1 &&
		victim->query_temp("guarding") )
	{
		victim->set_temp("guarding", 0);
		if( random(me->query_cps()) < 5 )
		{
//			message_vision("$Nһ�����У�¶����������\n", me);
			message_combatd("$Nһ�����У�¶����������\n", me);
// �����ֳ�ת�� start
//			if ((string)environment(me)->query("short") == "��̨")
//			for (userno=0; userno<sizeof(player); userno++)
//				if ((player[userno])->query_temp("view_leitai")&&
//             (string)environment(player[userno])->query("short") == "�����")
//				tell_object(player[userno], me->name()+"һ�����У�¶����������\n");
// �����ֳ�ת�� end
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
		} else
		{
//			message_vision("$N��$n����ʧ�󣬳û�����������\n", victim, me);
			message_combatd("$N��$n����ʧ�󣬳û�����������\n", victim, me);
// �����ֳ�ת�� start
//			if ((string)environment(me)->query("short") == "��̨")
//			for (userno=0; userno<sizeof(player); userno++)
//				if ((player[userno])->query_temp("view_leitai")&&
//             (string)environment(player[userno])->query("short") == "�����")
//				tell_object(player[userno], me->name()+"��"+victim->name()+"����ʧ�󣬳û�����������\n");
// �����ֳ�ת�� end
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}
	if(martial_skill = me->query_skill_mapped(attack_skill))
		SKILL_D(martial_skill)->double_attack(me, victim);  
}

//	fight()
//
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
	object ob;
	string result;

// �����ֳ�ת�� start
	player=users();
// �����ֳ�ת�� end
	
	if( !living(me) || me->query_temp("noliving") ) return;

//	if( !me->visible(victim)
//	&& (random(100 + (int)me->query_skill("perception")) < 100) )
//		return;

	// If victim is busy or unconcious, always take the chance to make an attack.
	if( victim->is_busy() ||
		!living(victim) || victim->query_temp("noliving") )
	{
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) && sizeof(me->query_skill_prepare()) > 1) ||					//������prepare��˫��
//			(objectp(me->query_temp("weapon")) && (me->query_temp("weapon"))->query("skill_type")=="sword" && me->query_skill("bixie-jian", 1) >= 60 && me->query_skill_mapped("sword") == "bixie-jian") || //��а60������˫��
// ��bixie-jian˫������ /kungfu/skill/bixie-jian.c �м�ȥ
			(me->query("double_attack") && !me->query_temp("weapon")) )							//����������prepare˫��
		{
			if (me->query("double_attack") &&
				sizeof(me->query_skill_prepare()) < 2)
				message_combatd(CYN"\n$N˫�ַ�ʹ������쳣�����������������Ƶģ�"NOR,me);
			me->set_temp("action_flag",1);
			do_attack(me,victim,me->query_temp("weapon"),TYPE_QUICK);
			me->set_temp("action_flag",0);
		}

	// Else, see if we are brave enough to make an aggressive action.
	} else if( random((int)victim->query_cps()*3 ) > (int)me->query_cor())
	{ 
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) && sizeof(me->query_skill_prepare()) > 1) ||					//������prepare��˫��
//			(objectp(me->query_temp("weapon")) && (me->query_temp("weapon"))->query("skill_type")=="sword" && me->query_skill("bixie-jian", 1) >= 60 && me->query_skill_mapped("sword") == "bixie-jian") || //��а60������˫��
// bixie˫������bixie-jian.c
			(me->query("double_attack") && !me->query_temp("weapon")) )							//����������prepare˫��
		{
			if (me->query("double_attack") &&
				sizeof(me->query_skill_prepare()) < 2)
				message_combatd(CYN"\n$N˫�ַ�ʹ������쳣�����������������Ƶģ�"NOR,me);
			me->set_temp("action_flag",1);
			do_attack(me, victim, me->query_temp("weapon"),TYPE_REGULAR);
			me->set_temp("action_flag",0);
		}

	// Else, we just start guarding.
	} else if( !me->query_temp("guarding") )
	{
		me->set_temp("guarding", 1);
		message_vision(guard_msg[random(sizeof(guard_msg))], me,victim);
//		message_combatd(guard_msg[random(sizeof(guard_msg))], me,victim);
// �����ֳ�ת�� start
		result = guard_msg[random(sizeof(guard_msg))];
		result = replace_string(result, "$P", me->name());
		result = replace_string(result, "$N", me->name());
		result = replace_string(result, "$n", victim->name());
		result = replace_string(result, "$p", victim->name());
		if ((string)environment(me)->query("short") == "��̨")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "�����")
				tell_object(player[userno], result);
// �����ֳ�ת�� end
		return;
	} else return;
}

//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	if( !me || !obj ) return;
	// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| me->query_temp("noliving")	// Is Player capable for a fight? 
	|| environment(me)!=environment(obj)	// Are we still inthe same room?
	|| environment(me)->query("no_fight")	// Are we in a peace room?
	) return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

	if(random(obj->query_per()) > me->query_cps())
	{
		if(obj->query("gender")=="Ů��" && me->query("gender")!="Ů��")
		{
			message_vision("$N����$n�ֶ࿴��һ�ۣ��޵�����ô�������˶����治������֡�\n", me, obj);
			return;
		}
		if(me->query("gender")=="Ů��" && obj->query("gender")!="Ů��")
		{
			message_vision("$N����$n�ֶ࿴��һ�ۣ��޵�����ô���ŵĿ��˶��������᲻�����֡�\n", me, obj);
			return;
		}
	}
	if(!userp(me) || (int)me->query("neili")>(random(shen)+shen)/10) return;

	if( shen > (int)me->query("score") && !wizardp(obj) )
	{
		message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
			+ "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
		me->kill_ob(obj);
	} else
	{
		message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
			+ "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n", me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return; // Are we still exist(not becoming a corpse)?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| me->query_temp("noliving")	// Is Player capable for a fight? 
	|| environment(me)!=environment(obj)	// Are we still in the sameroom?
	|| environment(me)->query("no_fight") 	// Are we in a peace room?
	) return;

	if( me->query_temp("owner") == obj->query("id")	// be trained
	|| obj->query_temp("owner") == me->query("id") 	// be trained
	) return;

	// We found our hatred! Charge!
	message_combatd(catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return; // Are we still exist( not becoming a corpse)?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| me->query_temp("noliving")	// Is Player capable for a fight? 
	|| environment(me)!=environment(obj) // Are we still in the same room?
	|| environment(me)->query("no_fight") 	// Are we in a peace room?
	) return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return; // Are we still exist( not becoming a corpse)?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| me->query_temp("noliving")	// Is Player capable for a fight? 
	|| environment(me)!=environment(obj) // Are we still in the same room?
	|| environment(me)->query("no_fight") 	// Are we in a peace room?
	) return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
// �����ֳ�ת�� start
	player=users();
// �����ֳ�ת�� end
	switch(event) {
		case "dead":
// �����ֳ�ת�� start
			message_vision(ob->query("dead_message"), ob);
//			message_combatd(ob->query("dead_message"), ob);
			if ((string)environment(ob)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "�����")
					tell_object(player[userno], "\n"+ob->name()+ob->query("dead_message"));
// �����ֳ�ת�� end
			break;
		case "unconcious":
			message_vision(ob->query("unconcious_message"), ob);
//			message_combatd(ob->query("unconcious_message"), ob);
// �����ֳ�ת�� start
			if ((string)environment(ob)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "�����")
//					tell_object(player[userno], "\n"+ob->name()+ob->query("unconcious_message"));
					tell_object(player[userno], "\n"+replace_string(ob->query("unconcious_message"),"$N",ob->name()));
// �����ֳ�ת�� end
			break;
		case "revive":
			message_vision(ob->query("revive_message"), ob);
//			message_combatd(ob->query("revive_message"), ob);
// �����ֳ�ת�� start
			if ((string)environment(ob)->query("short") == "��̨")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai")&&
             (string)environment(player[userno])->query("short") == "�����")
//					tell_object(player[userno], "\n"+ob->name()+ob->query("revive_message"));
					tell_object(player[userno], "\n"+replace_string(ob->query("revive_message"),"$N",ob->name()));
// �����ֳ�ת�� end
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
	string vmark, temp, msg="Ī�����������", quest_master = "";
	mapping quest, actions;
	int bls, exp, pot, score, bonus, factor, level, student_num;
  object weapon,faintby;
  string msg1;
	// Call the mudlib killer apply.
	killer->killed_enemy(victim);

	if( userp(victim) )
	{
		killer->add("PKS", 1);
//* ��pker������ ��ʱ��ʩ hoho
		killer->set_temp("LAST_PKER_TIME",time());

		victim->clear_condition();
// ���������
		if (victim->query("family/master_id") == "feng qingyang")
			CHAR_D->break_relation(this_object());
			//���ڷ�������bug 
			// һ��  �����break_relation(this_object()) 
			//       ����this_object()�Ͳ���
			//��һ�� char_d �У��ҷ����� ��find_object load_object
			//       Ȼ��presentѰ�ҷ磬 ���������ҵ���feng ��û��restore
			//       �������ҵ�feng����û����ͽ��¼
			// ������������ͬʱ���ڣ�����feng�����������ܵ�Ӱ��
/* old
			victim->set("family/master_id", "yue buqun");
			victim->set("family/master_name", "����Ⱥ");
			victim->set("family/generation", 14);
			victim->set("title", "��ɽ�ɵ�ʮ�Ĵ�����");
			victim->set("feng_dietime",victim->query("mud_age"));
			temp = read_file("/data/FENG", 1, 1);
			student_num = atoi(temp);
			student_num--;
			if(student_num == 0) temp = "0";
			else if(student_num == 1) temp = "1";
			else if(student_num == 2) temp = "2";
			write_file("/data/FENG", temp, 1);
*/
// Give the death penalty to the dying user.
		victim->add("shen", -(int)victim->query("shen") / 10);
		if (victim->query("max_neili")>2)
		{
			victim->add("max_neili", -2);
		}
		victim->add("combat_exp", -(int)victim->query("combat_exp")/50);
		victim->delete("vendetta");
		if( victim->query("thief") )
			victim->set("thief", (int)victim->query("thief") / 2);
		if( (int)victim->query("potential") > (int)victim->query("learned_points"))
			victim->add("potential",((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
		victim->skill_death_penalty();
		if(victim->query_temp("LAST_PKER_TIME"))
			victim->delete_temp("LAST_PKER_TIME");
		victim->save();
    
		bls = 10;

		if(objectp(killer))
		{
			msg="��";
			 if (objectp(faintby=victim->query_temp("faint_by")) &&
      			 	faintby != killer )
			 	 msg+=sprintf("%s���κ󣬱�%s%s�û�",
			 	       faintby->name(1),
			 	       faintby->name(1)==killer->name(1)? "��һ"+killer->query("unit"):"",
               killer->name(1));
       else
         msg+=killer->name(1);
			msg1="��";
      msg1+=killer->name(1);
			actions = killer->query("actions");
			switch(actions["damage_type"])
			{
				case "����":
				case "����": msg+="������";msg1+="������"; break;
				case "����": msg+="������";msg1+="������"; break;
				case "����": msg+="������";msg1+="������"; break;
				case "����": msg+="������";msg1+="������"; break;
				default: msg+="ɱ����";msg1+="ɱ����";
			}
		}
		victim->set("last_die_msg",msg);
		victim->set("last_die_by_name",killer->name());
		victim->set("last_die_by_id",killer->query("id"));
    if (victim->query("max_nuqi"))
    victim->set("nuqi",victim->query("max_nuqi"));
    victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("�ҿ���%s"+msg1+"�����Ǻòҡ�", victim->name(1)));
		write_file("/log/static/KILLRECORD",sprintf("%s (%s) ɱ���� %s (%s) on %s\n", killer->name(1), killer->query("id"), victim->name(1), victim->query("id"), ctime(time()) ));
	}
	else
	{
		killer->add("MKS", 1);
		bls = 1;
	}
   if (victim->query("id")==killer->query("last_die_by_id"))
      {
			tell_object(killer,sprintf("������ǧ����࣬����ɱ����%s������Ѫ�����\n", victim->name(1)));
      killer->set("nuqi",0);
      tell_object(killer,"�����е�ŭ������ƽϢ��������\n");
      killer->delete("last_die_by_id");
      killer->delete("last_die_by_name");
      killer->delete("last_die_msg");
      victim->set("last_die_msg",sprintf("%s����ѩ�ޣ�ɱ������",killer->name(1)));
      if (victim->query("nuqi"))
      victim->set("nuqi",victim->query("nuqi")/2);
    }
  if (objectp(weapon=killer->query_temp("weapon")) && 
  weapon->query("ownmake") && weapon->query("owner")==killer->query("id"))
   	killer->add("weapon/killed",1);
	if( (userp(killer) || killer->query("is_baby")) && killer->query("combat_exp") < victim->query("combat_exp")) 
		killer->add("shen", -(int)victim->query("shen") / 10);

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

// ������ɱ�˶��ı� ���� -= WKS + IKS * 4 + IOKS * 8 + BKS * 2 + BOKS * 4
	if(!victim->query("family") && victim->query("race")=="����")
	{
		killer->add("WKS", 1); // ��ɱ�޹�����Ŷ
		if(victim->query("age") < 17 )
			killer->add("WKS1", 1); // ��ɱ��ͯ
	}
	if(killer->query("family") &&
		killer->query("family/family_name") ==
		victim->query("family/family_name"))
	{
		killer->add("IKS", 1); // ������ڧ�����ۼ� internal conflict
		if(killer->query("family/generation") >
			victim->query("family/generation"))
			killer->add("IKS1", 1); // ���ϴ����ۼ� 
			
	}
	if(killer->query("party") &&
		killer->query("party/party_name") ==
		victim->query("party/party_name"))
	{
		killer->add("BKS", 1); // �����ڧ�����ۼ�
		if(killer->query("party/level") <
			victim->query("party/level"))
			killer->add("BKS1", 1); // ���ϴ����ۼ� 
	}
// ������ɱ������ 
	if (userp(victim) || victim->query("race")!="����") return;
	if( interactive(killer) )
	{
		if ( ( quest = killer->query("quest/shan") ) &&
			(int)killer->query("quest/shan/time") >= time() &&
			( !killer->query("quest/shan/lock") ) &&
			( !killer->query("quest/shan/finished") ) &&
			quest["quest"]==victim->query("name"))
			quest_master = "shan";
			
		if ( ( quest_master == "" ) &&
			( quest = killer->query("quest/helian") ) &&
			(int)killer->query("quest/helian/time") >= time() &&
			( !killer->query("quest/helian/lock") ) &&
			( !killer->query("quest/helian/finished") ) &&
			quest["quest"]==victim->query("name"))
			quest_master = "helian";
		
		if ( quest_master == "" ) return;
						
		tell_object(killer,"��ϲ�㣡���������һ������\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
		score = quest["score"]/2 + random(quest["score"]/2);
		exp = exp * 10 / 8;
		pot = pot * 10 / 8;
		score = score * 10 / 8;
		factor=victim->query("quest/" + quest_master + "/factor");
		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
		bonus = (int) killer->query("combat_exp");
		bonus += exp;
		killer->set("combat_exp", bonus);
		killer->set_temp("can_give_prize",1);
		killer->set_temp("prize_exp",exp);
		killer->set_temp("prize_pot",pot);
		killer->set_temp("prize_reason","ɱ��");
		bonus = (int) killer->query("potential");
		bonus = bonus - (int) killer->query("learned_points");
		bonus = bonus + pot;
//		if( bonus > 300) bonus = 300;
		bonus += (int)killer->query("learned_points");
		killer->set("potential", bonus );
		bonus = (int) killer->query("score");
		bonus += score;
		killer->set( "score", bonus );

		killer->add("shen", -(int)victim->query("shen") / 30);
/*
		bonus = (int)killer->query("shen");
		if(bonus >= 0)
			bonus += score;
		else
			bonus -= score;
		killer->set("shen", bonus);
*/
		tell_object(killer,HIW"�������Ŭ��ƴɱ����������" + chinese_number(exp) + "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܺ�" + chinese_number(score)+"�㽭��������\n" NOR);
		quest_finished( killer, quest_master );
	}
}

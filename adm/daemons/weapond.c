// weapond.c

#include <ansi.h>
#include <combat.h>

mapping weapon_actions = ([
	"slash": ([
		"damage_type":  "����",
		"action":       "$N�Ӷ�$w��ն��$n��$l",
		"parry":        20,
		"post_action":  (: call_other, __FILE__, "slash_weapon" :),
	]),
	"slice": ([
		"damage_type":  "����",
		"action":       "$N��$w��$n��$l��ȥ",
		"dodge":        20,
		"post_action":  (: call_other, __FILE__, "slash_weapon" :),
	]),
	"chop": ([
		"damage_type":  "����",
		"action":       "$N��$w����$n��$l������ȥ",
		"parry":        -20,
		"post_action":  (: call_other, __FILE__, "slash_weapon" :),
	]),
	"hack": ([
		"action":       "$N����$w����׼$n��$lһ���ҿ�",
		"damage_type":  "����",
		"damage":       30,
		"dodge":       	30,
		"post_action":  (: call_other, __FILE__, "slash_weapon" :),
	]),
	"thrust": ([
		"damage_type":  "����",
		"action":       "$N��$w��$n��$l��ȥ",
		"dodge":        15,
		"parry":        -15,
		"post_action":  (: call_other, __FILE__, "slash_weapon" :),
	]),
	"pierce": ([
		"action":       "$N��$w��$n��$l�ݺݵ�һͱ",
		"damage_type":  "����",
		"dodge":        -30,
		"parry":        -30,
		"post_action":  (: call_other, __FILE__, "slash_weapon" :),
	]),
	"whip": ([
		"action":       "$N��$wһ���$n��$l��ȥ",
		"damage_type":  "����",
		"dodge":        -20,
		"parry":        30,
	]),
	"impale": ([
		"action":       "$N��$w��$n��$lֱ����ȥ",
		"damage_type":  "����",
		"dodge":        -10,
		"parry":        -10,
		"post_action":  (: call_other, __FILE__, "slash_weapon" :),
	]),
	"strike": ([
		"action":       "$Nһ�����������$w������$n��$l����һ��",
		"damage_type":  "����",
		"dodge":        -10,
		"parry":        -10,
		"post_action":  (: call_other, __FILE__, "slash_weapon" :),
	]),
	"bash": ([
		"action":       "$N����$w����$n��$l����һ��",
		"damage_type":  "����",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	"crush": ([
		"action":       "$N�߸߾���$w����$n��$l��ͷ����",
		"damage_type":  "����",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	"slam": ([
		"action":       "$N����$w����¶�׹⣬�͵ض�׼$n��$l���˹�ȥ",
		"damage_type":  "����",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	"throw": ([
		"action":       "$N��$w��׼$n��$l���˹�ȥ",
		"damage_type":  "����",
		"post_action":  (: call_other, __FILE__, "throw_weapon" :),
	]),
]);

varargs mapping query_action()
{
	string verb, *verbs;

	verbs = previous_object()->query("verbs");

	if( !pointerp(verbs) ) return weapon_actions["hit"];
	else {
		verb = verbs[random(sizeof(verbs))];
		if( !undefinedp(weapon_actions[verb]) )
			return weapon_actions[verb];
		else return weapon_actions["hit"];
	}	
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
	if( objectp(weapon) )
	{
		if( (int)weapon->query_amount()==1 )
		{
			weapon->unequip();
			tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n\n");
		}
		weapon->add_amount(-1);
	}
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
	object ob;
	int wap, wdp;

	if( objectp(weapon) && damage==RESULT_PARRY &&
		ob = victim->query_temp("weapon") )
	{
		wap = (int)weapon->weight() / 500
			+ (int)weapon->query("rigidity")
			+ (int)me->query("str");
		wdp = (int)ob->weight() / 500
			+ (int)ob->query("rigidity")
			+ (int)victim->query("str");
		wap = random(wap);

		if( wap > 5 * wdp)
		{
			message_vision(HIM"ֻ������ž����һ����$N���е�"+ob->name()+HIM"�Ѿ���Ϊ���أ�\n"NOR,victim);
			ob->unequip();
			ob->move(environment(victim));
			ob->set("name","�ϵ���"+ob->query("name"));
			ob->set("value", 49);
			ob->set("weapon_prop", 0);
			victim->reset_action();
		} 
		else if( wap > 3 * wdp )
			{
				message_vision(HIY"$Nֻ��������"+ob->name()+HIY"�ѳֲ��������ַɳ���\n"NOR,victim);
				ob->unequip();
				ob->move(environment(victim));
				victim->reset_action();
			} 
			else if( wap > wdp )
				{
					message_vision(HIW "$Nֻ��������" + ob->name() + HIW"һ����Щ���֣�\n"NOR, victim);
				}
				else
				{
					message_vision(HIR"$N��"+weapon->name()+HIR"��$n��"+ob->name()+HIR"�����ð�����Ļ��ǡ�\n"NOR,me,victim);
				}
	}
}

void slash_weapon(object me, object victim, object weapon, int damage)
{
	object weapon1;        
	string poison;
	int poison1, wp, wp1, wp2;  
	weapon1=victim->query_temp("weapon");

	if(objectp(weapon) && objectp(weapon1))
	{
		wp = weapon->query("weapon_prop/damage");
		wp1 = weapon1->query("weapon_prop/damage");
		wp2 = weapon1->query("rigidity");
		if(wp > 1000) wp = 1000;
		if(wp1 > 1000) wp1 = 1000;
		if(wp2 > 100) wp2 = 100;
		if( wp > 0 && wp > (wp1 + wp2) * 5 &&
			random(me->query("str")) > victim->query("str")/2)
		{
			message_vision(WHT "ֻ�������ѡ���һ�����죬$N���е�"+weapon1->name()+WHT"�Ѿ���"+weapon->name()+WHT"��Ϊ���أ�\n"NOR, victim );
			weapon1->unequip();
			weapon1->move(environment(victim));
			weapon1->set("name", "�ϵ���"+weapon1->query("name"));
			weapon1->set("value", 49);
			weapon1->set("weapon_prop", 0);
			victim->reset_action();
		} 
	}

	if (stringp(poison=weapon->query("poisoned")) && 
		((int)victim->query("eff_qi") < (int)victim->query("max_qi"))) 
		if(intp(poison1=weapon->query("poison_number")) && random(10)> 5
			&& poison1 > 1 && victim->query_condition(poison) < 50)
		{
			if (poison1 == 2)                   
				weapon->set_temp("apply/long", ({weapon->query("long")+"�����Ǳ�ι���綾������Ч���Ѿ��������ˡ�\n"}));
				weapon->add("poison_number", -1);
				victim->apply_condition(poison, victim->query_condition(poison) + random(10));
				message_vision(HIR"$nֻ�����˿���һ�飬���һ�������ã�\n"NOR,me,victim);
				if(!victim->is_killing(me->query("id"))) victim->kill_ob(me);
		}
}


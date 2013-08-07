// Last Modified by winder on Feb. 28 2001
// Poisoned weapon
// set("poisoned", "poison-name");

#include <ansi.h>
#include <combat.h>

mixed hit_ob(object me, object victim, int damage)
{
	object weapon, weapon1;	
	string poison;
	int poison1, wp, wp1, wp2, wap, wdp;
	object piece;
	weapon=this_object();
	weapon1=victim->query_temp("weapon");

	if(objectp(weapon) && objectp(weapon1) && weapon->query("flag") == 4)
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
			message_vision(HIM"ֻ�������ѡ���һ�����죬$N���е�"+weapon1->name()+HIY"�Ѿ���"+weapon->name()+HIY"��Ϊ���أ�\n"NOR,victim);
			weapon1->unequip();
			victim->reset_action();
     	seteuid(getuid());
     	piece = new("/clone/misc/piece");
     	piece->set("long", "�ϳ����ص�"+weapon1->query("name")+"��\n");
     	piece->set_name( "�ϵ���"+weapon1->query("name"), ({weapon1->query("id"),"piece"}) );
     	piece->move(environment(victim));
    	destruct(weapon1);
		} 
	}
	else
		if( objectp(weapon) && objectp(weapon1) && 
			weapon1->query("material") != "softsteel" &&
			weapon1->query("skill_type") != "whip" &&
			weapon1->query("rigidity") < weapon->query("rigidity") &&
			!weapon1->query("rao") ) //��ָ�ὣ
		{
			wap = (int)weapon->weight() / 500 +
				(int)weapon->query("rigidity") +
				(int)me->query("str");
			if(weapon->query_amount() > 1)
				wap = ((int)weapon->query("base_weight") *
					weapon->query_amount() / 500) +
					(int)weapon->query("rigidity") +
					(int)me->query("str");
			wdp = (int)weapon1->weight() / 500 +
				(int)weapon1->query("rigidity") +
				(int)victim->query("str");
			if(weapon1->query_amount() > 1)
				wap = ((int)weapon1->query("base_weight") *
					weapon1->query_amount() / 500) +
					(int)weapon1->query("rigidity") +
					(int)victim->query("str");
			wap = random(wap);
			if( wap > 5 * wdp)
			{
				message_vision(HIM"ֻ������ž����һ����$N���е�"+weapon1->name()+HIM"�Ѿ���Ϊ���أ�\n"NOR,victim);
				weapon1->unequip();
				victim->reset_action();
       	seteuid(getuid());
       	piece = new("/clone/misc/piece");
      	piece->set("long", "�ϳ����ص�"+weapon1->query("name")+"��\n");
      	piece->set_name( "�ϵ���"+weapon1->query("name"), ({weapon1->query("id"),"piece"}) );
     	  piece->move(environment(victim));
      	destruct(weapon1);
			} 
			else if( wap > 3 * wdp )
				{
					message_vision(HIY"$Nֻ��������"+weapon1->name()+HIY"�ѳֲ��������ַɳ���\n"NOR,victim);
					weapon1->unequip();
					weapon1->move(environment(victim));
					victim->reset_action();
				} 
				else if( wap > wdp )
					{
						message_vision(HIW "$Nֻ��������" + weapon1->name() + HIW"һ����Щ���֣�\n"NOR, victim);
					}
					else
					{
						message_vision(HIR"$N��"+weapon->name()+HIR"��$n��"+weapon1->name()+HIR"�����ð�����Ļ��ǡ�\n"NOR,me,victim);
					}
		}

	if (stringp(poison=weapon->query("poisoned")) && 
		((int)victim->query("eff_qi") < (int)victim->query("max_qi"))) 
		if(intp(poison1=weapon->query("poison_number")) &&
			random(10) > 5 && poison1 > 1 &&
			victim->query_condition(poison) < 50)
		{
			if (poison1 == 2)
				weapon->set_temp("apply/long", ({weapon->query("long")+"�����Ǳ�ι���綾������Ч���Ѿ��������ˡ�\n"}));
			weapon->add("poison_number", -1);
			victim->apply_condition(poison, victim->query_condition(poison) + random(10));
			if(victim->query("race") == "����" && !victim->query("mute"))
				message_vision(HIR "$Nֻ�����˿���һ�飬���һ�������ã�\n"NOR,victim);
			else if(victim->query("race") == "����")
				message_vision(HIR "$Nֻ�����˿���һ�飬üͷһ������Ȼ�Ƿ�ŭ�ˣ�\n"NOR,victim);
				else message_vision(HIR"$N��Ȼһ�����˿ڴ�������Ѫ�������¶��\n"NOR,victim);
			if(!victim->is_killing(me->query("id"))) victim->kill_ob(me);
		}
	return this_object()->weapon_hit_ob(me, victim, damage);
}


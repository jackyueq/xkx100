// /adm/daemons/combatd.c
// Modified by Zeratul Jan 5 2001

#pragma optimize all

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include </quest/quest.h>

inherit F_DBASE;

object *player;
int userno;

string *guard_msg = ({
	CYN "$N注视着$n的行动，企图寻找机会出手。\n" NOR,
	CYN "$N正盯着$n的一举一动，随时准备发动攻势。\n" NOR,
	CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
	CYN "$N目不转睛地盯着$n的动作，寻找进攻的最佳时机。\n" NOR,
	CYN "$N慢慢地移动着脚步，伺机出手。\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
	HIW "$N对着$n大喝：「可恶，又是你！」\n" NOR,
	HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
	HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
	HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
	HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
	HIW "$N对着$n大叫：「不知死活的东西，让我来超渡你吧！」\n" NOR,
	HIW "$N喝道：「$n，看招！」\n" NOR,});

string *winner_msg = ({
	CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
	CYN "\n$N双手一拱，笑着说道：承让！\n\n" NOR,
	CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
	CYN "\n$N双手一拱，笑着说道：知道我的利害了吧！\n\n" NOR,
	CYN "\n$n向后退了几步，说道：这场比试算我输了，下回看我怎么收拾你！\n\n" NOR,
	CYN "\n$n向后一纵，恨恨地说道：君子报仇，十年不晚！\n\n" NOR,
	CYN "\n$n脸色一寒，说道：算了算了，就当是我让你吧！\n\n" NOR,
	CYN "\n$n纵声而笑，叫道：“你运气好！你运气好！”一面身子向后跳开。\n\n" NOR,
	CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
	CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
	CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});

void create()
{
	seteuid(getuid());
	set("name", "战斗精灵");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "造成 " + damage + " 点" + type + "。\n";

	if( damage == 0 ) return "结果没有造成任何伤害。\n";

	switch( type ) {
	case "擦伤":
	case "割伤":
		if( damage < 10 ) return "结果只是轻轻地划破$p的皮肉。\n";
		else if( damage < 20 ) return "结果在$p$l划出一道细长血痕。\n";
		else if( damage < 40 ) return "结果「嗤」一声划出一道伤口！\n";
		else if( damage < 80 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
		else if( damage < 160 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
		else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
		break;
	case "刺伤":
		if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
		else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
		else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
		else if( damage < 80 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
		else if( damage < 160 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉□糊的血窟窿！\n";
		else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
		break;
	case "瘀伤":
		if( damage < 10 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
		else if( damage < 20 ) return "结果在$p的$l造成一处瘀青。\n";
		else if( damage < 40 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
		else if( damage < 80 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
		else if( damage < 120 ) return "结果「砰」地一声，$n退了两步！\n";
		else if( damage < 160 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
		else if( damage < 240 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
		else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
		break;
	case "内伤":
		if( damage < 10 ) return "结果只是把$n打得退了半步，毫发无损。\n";
		else if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
		else if( damage < 40 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
		else if( damage < 80 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
		else if( damage < 120 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
		else if( damage < 160 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
		else if( damage < 240 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
		else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		break;
	default:
		if( !type ) type = "伤害";
		if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
		else if( damage < 20 ) str = "结果造成轻微的";
		else if( damage < 30 ) str = "结果造成一处";
		else if( damage < 50 ) str = "结果造成一处严重";
		else if( damage < 80 ) str = "结果造成颇为严重的";
		else if( damage < 120 ) str = "结果造成相当严重的";
		else if( damage < 170 ) str = "结果造成十分严重的";
		else if( damage < 230 ) str = "结果造成极其严重的";
		else str =  "结果造成非常可怕的严重";
		return str + type + "！\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
	if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
	if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
	if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
	if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤着实不轻。" NOR;
	if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑着不倒下去。" NOR;
	if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
	if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
	if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
	return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
	if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
	if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
	if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
	if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
	if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑着不倒下去。" NOR;
	if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
	if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
	return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

varargs void report_status(object ob, int effective)
{
// 比武现场转播 start
	player=users();
// 比武现场转播 end
	if( effective ) 
	{
		message_vision( "( $N" + eff_status_msg(
			(int)ob->query("eff_qi")*100 / (int)ob->query("max_qi"))
			+ " )\n", ob);
// 比武现场转播 start
		if ((string)environment(ob)->query("short") == "擂台")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], "( " + ob->name() + eff_status_msg((int)ob->query("eff_qi")*100 / (int)ob->query("max_qi"))+" )\n");
// 比武现场转播 end
	}
	else
	{
		message_vision( "( $N" + status_msg(
			(int)ob->query("qi") * 100 / (int)ob->query("max_qi")) 
			+ " )\n", ob);
// 比武现场转播 start
		if ((string)environment(ob)->query("short") == "擂台")
		for (userno=0; userno<sizeof(player); userno++)
			if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], "( " + ob->name() + status_msg( (int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) + " )\n");
// 比武现场转播 end
	}
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int status, level, power;

	if( !living(ob) ) return 0;

	level = ob->query_skill(skill);
	switch(usage)
	{
		case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level += ob->query_temp("apply/defense");
			if (ob->is_fighting())
				level = level * (100 + ob->query_temp("fight/dodge")) / 100;
			break;
	}

	if( !level ) return (int)ob->query("combat_exp") / 2;

	power = (level / 6)*level*level;

	if (usage == SKILL_USAGE_ATTACK)
//		return (power + ob->query("combat_exp")) * ob->query_str() / 40;
		return (power + ob->query("combat_exp")) / 60 * (ob->query_str() + ob->query("str"));
	else
//		return (power + ob->query("combat_exp")) * ob->query_dex() / 40;
		return (power + ob->query("combat_exp")) / 60 * (ob->query_dex() + ob->query("dex"));
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
	mapping my, your, prepare, action;
	string limb, *limbs, result;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int ap, dp, pp;
	int damage, damage_bonus, defense_factor;
	int cost;
	int wounded = 0;

// 比武现场转播 start
	player=users();
// 比武现场转播 end

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
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
		me->reset_action();
		action = me->query("action");
		if( !mapp(action) )
		{
			CHANNEL_D->do_channel( this_object(), "sys",
				sprintf("%s(%s): bad action = %O",
			me->name(1), me->query("id"), me->query("actions", 1)));
			return 0;
		}
	}

	if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "！\n";
	else
		result = "\n" + "紧跟着"+action["action"] + "!\n"; 

	//
	// (2) Prepare AP, DP for checking if hit.
	//
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];

	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	if( ap < 1) ap = 1;
	if (userp(me) && intp(action["dodge"]))
		me->set_temp("fight/dodge", action["dodge"]);

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	if( victim->is_busy() ) dp /= 3;

	//
	// (3) Fight!
	//     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
	//     AP and DP are greater than zero, so we always have chance to hit
	//     or be hit.
	//

// Java 改随机数
//	if( random(100) > dp * 100 / (ap + dp) ) {

	if( random(ap + dp) < dp && !(victim->query_temp("pixie/cizu")))
		// Does the victim dodge this hit?
		// 辟邪刺足者无法躲闪
	{
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

		if( dp < ap && (!userp(victim) || !userp(me)) 
		&& random(your["jing"]*100/your["max_jing"]+your["int"]) > 50)
		{
			your["combat_exp"] += 1;
			victim->improve_skill("dodge", 1);
		}

// This is for NPC only. NPC have chance to get exp when fail to hit.
		if( (ap < dp) && !userp(me) )
		{
			if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
			me->improve_skill(attack_skill, random(my["int"]));
		}
		damage = RESULT_DODGE;
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
		if( pp < 1 ) pp = 1;

		if( random(ap + pp)< pp && !(victim->query_temp("pixie/ciwan")))
		// 辟邪刺腕者无法招架
		{
			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill ) parry_skill = "parry";
// change to SKILL_D(parry_skill) after added parry msg to those
// martial arts that can parry.
			result += SKILL_D("parry")->query_parry_msg(weapon);

			if( dp < ap && (!userp(victim) || !userp(me)) 
			&& random(your["jing"]*100/your["max_jing"] + your["int"]) > 50 )
			{
				your["combat_exp"] += 1;
				victim->improve_skill("parry", 1);
			}
			damage = RESULT_PARRY;
		} else
		{
		//
		//	(5) We hit the victim and the victim failed to parry
		//
			damage = me->query_temp("apply/damage");
			damage = (damage + random(damage)) / 2;
			if( action["damage"] )
//				damage += action["damage"] * damage / 100;
//减弱威力
			damage+=action["damage"]*damage /200;
//add by sega,让护甲可以抵消部分兵器的伤害
			damage -=(int)victim->query_temp("apply/armor");
			if (damage<0) damage=0;

			damage_bonus = me->query_str();

			// Let force skill take effect.
			if( my["jiali"] && (my["neili"] > my["jiali"]) )
			{
				if(force_skill=me->query_skill_mapped("force")) 
				{ 
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					else if(intp(foo) ) damage_bonus += foo;
				}
					//add by sega,被打中的效果
                                if(force_skill=victim->query_skill_mapped("force")) 
                                {

					foo = SKILL_D(force_skill)->be_hit_ob(victim,me, damage_bonus, my["jiali"]);
					if( stringp(foo) ) result += foo;
					else if(intp(foo) ) damage_bonus += foo;

				}
			}

			if( action["force"] )
//				damage_bonus+=action["force"]*damage_bonus/100;
//减弱威力
			        damage_bonus+=action["force"]*damage_bonus/200;	
			if(martial_skill = me->query_skill_mapped(attack_skill))
			{
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}
                        if(martial_skill = victim->query_skill_mapped("parry"))
                        {

				//add by sega 被打中效果
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
				damage += (damage_bonus+random(damage_bonus))/2;
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
			// 空明拳化解伤害力
			{
				if( damage > 50) damage = damage / 5;
				else damage = 10;
			}
			damage = victim->receive_damage("qi", damage, me );

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
				if( (ap < dp)
				&& (random(my["jing"]*100/my["max_jing"] + my["int"]) > 30) )
				{
					my["combat_exp"] += 1;
					if( my["potential"] - my["learned_points"] < 100 )
						my["potential"] += 1;
					me->improve_skill(attack_skill, 1);
				}
				if(random(your["max_qi"]+your["qi"]) < damage)
				{
					your["combat_exp"] += 1;
					if( your["potential"] - your["learned_points"] < 100 )
						your["potential"] += 1;
				}
			}
		}
	} 

	result = replace_string( result, "$l", limb );
	if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "finger" ) 
		result = replace_string( result, "$w", "手指" );

//	message_vision(result, me, victim );
	message_combatd(result, me, victim );

// 比武现场转播 start
//	result = replace_string(result,  "$P", me->name());
//	result = replace_string(result,  "$N", me->name());
//	result = replace_string(result,  "$n", victim->name());
//	result = replace_string(result,  "$p", victim->name());
//	if ((string)environment(me)->query("short") == "擂台")
//	for (userno=0; userno<sizeof(player); userno++)
//	    if ((player[userno])->query_temp("view_leitai"))
//		tell_object(player[userno], result);
// 比武现场转播 end

	if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) 
	{
		if( damage > 0 )
			tell_object(me, sprintf( GRN "攻击：%d，躲避：%d，招架：%d，伤害力：%d\n" NOR, ap/100, dp/100, pp/100, damage));
		else
			tell_object(me, sprintf( GRN "攻击：%d，躲避：%d，招架：%d\n" NOR, ap/100, dp/100, pp/100));
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
// 比武现场转播 start
		result = winner_msg[random(sizeof(winner_msg))];
		result = replace_string(result,  "$P", me->name());
		result = replace_string(result,  "$N", me->name());
		result = replace_string(result,  "$n", victim->name());
		result = replace_string(result,  "$p", victim->name());
		if ((string)environment(me)->query("short") == "擂台")
		for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], result);
// 比武现场转播 end
		}
	}

	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);

	// See if the victim can make a riposte.
	if( attack_type==TYPE_REGULAR
	&&	damage < 1
	&&	victim->query_temp("guarding") ) {
		victim->set_temp("guarding", 0);
		if( random(my["cps"]) < 5 )
		{
			message_vision("$N一击不中，露出了破绽！\n", me);
// 比武现场转播 start
			if ((string)environment(me)->query("short") == "擂台")
			for (userno=0; userno<sizeof(player); userno++)
			    if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], me->name()+"一击不中，露出了破绽！\n");
// 比武现场转播 end
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
		} else
		{
			message_vision("$N见$n攻击失误，趁机发动攻击！\n", victim, me);
// 比武现场转播 start
			if ((string)environment(me)->query("short") == "擂台")
			for (userno=0; userno<sizeof(player); userno++)
			    if ((player[userno])->query_temp("view_leitai"))
				tell_object(player[userno], me->name()+"见"+victim->name()+"攻击失误，趁机发动攻击！\n");
// 比武现场转播 end
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}
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

// 比武现场转播 start
	player=users();
// 比武现场转播 end
	
	if( !living(me) ) return;

//	if( !me->visible(victim)
//	&& (random(100 + (int)me->query_skill("perception")) < 100) )
//		return;

	// If victim is busy or unconcious, always take the chance to make an attack.
	if( victim->is_busy() || !living(victim) )
	{
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) 
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon")) 
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian") )
		{
		   me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		   me->set_temp("action_flag",0);
	     	}

	// Else, see if we are brave enough to make an aggressive action.
	} else if( random((int)victim->query("cps")*3 ) > (int)me->query("cor"))
	{ 
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);  
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

		if( me->is_fighting(victim) && victim->is_fighting(me)) 
		if( (!objectp(me->query_temp("weapon")) 
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon")) 
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian") )
		{
		   me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"),TYPE_REGULAR);
		   me->set_temp("action_flag",0);
	     	}

	// Else, we just start guarding.
	} else if( !me->query_temp("guarding") )
	{
		me->set_temp("guarding", 1);
		message_vision(guard_msg[random(sizeof(guard_msg))], me,victim);
// 比武现场转播 start
		result = guard_msg[random(sizeof(guard_msg))];
		result = replace_string(result,  "$P", me->name());
		result = replace_string(result,  "$N", me->name());
		result = replace_string(result,  "$n", victim->name());
		result = replace_string(result,  "$p", victim->name());
		if ((string)environment(me)->query("short") == "擂台")
		for (userno=0; userno<sizeof(player); userno++)
		    if ((player[userno])->query_temp("view_leitai"))
			tell_object(player[userno], result);
// 比武现场转播 end
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

	if( me->is_fighting(obj)	// Are we busy fighting?
	|| !living(me)		// Are we capable for a fight?
	|| environment(me)!=environment(obj)  // Are we still in the same room?
	|| environment(me)->query("no_fight")	// Are we in a peace room?
	) return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N用一种异样的眼神扫视着在场的每一个人。\n", me);

//	if((obj->query_per())*500+(obj->query_cps())*500 > random(shen)) return;
	if(obj->query_per() > me->query_cps())
	{
		if(obj->query("gender")=="女性" && me->query("gender")!="女性")
		{
			message_vision("$N对着$n又多看了一眼，赞道：这么靓丽的人儿，真不舍得下手。\n", me, obj);
			return;
		}
		if(me->query("gender")=="女性" && obj->query("gender")!="女性")
		{
			message_vision("$N对着$n又多看了一眼，赞道：这么俊雅的可人儿，真是舍不得下手。\n", me, obj);
			return;
		}
	}
	if(!userp(me) || (int)me->query("neili")>(random(shen)+shen)/10) return;

	if( shen > (int)me->query("score") && !wizardp(obj) )
	{
		message_vision("$N对着$n喝道：" + RANK_D->query_self_rude(me)
			+ "看你实在很不顺眼，去死吧。\n", me, obj);
		me->kill_ob(obj);
	} else
	{
		message_vision("$N对着$n喝道：喂！" + RANK_D->query_rude(obj)
			+ "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n", me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return; // Are we still exist(not becoming a corpse)?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)				// Are we capable for a fight?
	|| environment(me)!=environment(obj)  // Are we still in the same room?
	|| environment(me)->query("no_fight") 	// Are we in a peace room?
	) return;

	if( me->query_temp("owner") == obj->query("id")	// be trained
	|| obj->query_temp("owner") == me->query("id") 	// be trained
	) return;

	// We found our hatred! Charge!
	message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return; // Are we still exist( not becoming a corpse)?

	me->set_temp("looking_for_trouble", 0);

	if( me->is_fighting(obj)		// Are we busy fighting?
	|| !living(me)			// Are we capable for a fight?
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
// 比武现场转播 start
	player=users();
// 比武现场转播 end
	switch(event) {
		case "dead":
message_vision( NOR"\n$N扑在地上挣扎了几下，腿一伸，口中喷出几口"HIR"鲜血"NOR"，死了！\n\n" NOR, ob);
// 比武现场转播 start
			if ((string)environment(ob)->query("short") == "擂台")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai"))
					tell_object(player[userno], "\n"+ob->name()+"扑在地上挣扎了几下，腿一蹬，口中喷出几口鲜血就死了。\n");
// 比武现场转播 end
			break;
		case "unconcious":
			message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
// 比武现场转播 start
			if ((string)environment(ob)->query("short") == "擂台")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai"))
					tell_object(player[userno], "\n"+ob->name()+"脚下一个不稳，跌在地上一动也不动了。\n\n");
// 比武现场转播 end
			break;
		case "revive":
			message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n",ob);
// 比武现场转播 start
			if ((string)environment(ob)->query("short") == "擂台")
			for (userno=0; userno<sizeof(player); userno++)
				if ((player[userno])->query_temp("view_leitai"))
					tell_object(player[userno], "\n"+ob->name()+"慢慢睁开眼睛，清醒了过来。\n\n");
// 比武现场转播 end
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
	int bls;
	string vmark;
	string temp;
	string msg="莫名其妙地死了。";
	mapping quest, actions;
	int exp, pot, score, bonus,factor;
	int student_num;
	string quest_master = "";

	// Call the mudlib killer apply.
	killer->killed_enemy(victim);

	if( userp(victim) )
	{
		killer->add("PKS", 1);
		victim->clear_condition();
		// Give the death penalty to the dying user.
		if (victim->query("family/master_id") == "feng qingyang")
		{
			victim->delete("family");
			victim->set("class","");
			victim->set("title","普通百姓");
			victim->set("feng_dietime",victim->query("mud_age"));
			temp = read_file("/data/FENG", 1, 1);
			student_num = atoi(temp);
			student_num--;
			if(student_num == 0)
				temp = "0";
			else if(student_num == 1)
				temp = "1";
			else if(student_num == 2)
				temp = "2";
			write_file("/data/FENG", temp, 1);
		}
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
		victim->save();

		bls = 10;
		if(objectp(killer))
		{
			msg="被"+killer->name();
			actions = killer->query("actions");
			switch(actions["damage_type"]) {
			case "擦伤":
		        case "割伤":
				msg+="砍死了。";
				break;
			case "刺伤":
				msg+="刺死了。";
				break;
			case "瘀伤":
				msg+="击死了。";
				break;
			case "内伤":
				msg+="震死了。";
				break;
			default:
				msg+="杀死了。";
			}
		}
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("我看到%s"+msg+"真是好惨。", victim->name(1)));
		write_file("/log/static/KILLRECORD",sprintf("%s   杀死了   %s on %s\n", killer->name(1),victim->name(1), ctime(time()) ));
	} else
	{
		killer->add("MKS", 1);
		bls = 1;
	}

	if( userp(killer) && killer->query("combat_exp") < victim->query("combat_exp")) 
		killer->add("shen", -(int)victim->query("shen") / 10);

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);
// 下面是杀人任务 
	if (userp(victim))
	{
		return;
	}
	if( interactive(killer) )
	{
		if ( ( quest = killer->query("quest/shan") )
		&& (int)killer->query("quest/shan/time") >= time()
		&& ( !killer->query("quest/shan/lock") )
		&& ( !killer->query("quest/shan/finished") )
		&& quest["quest"]==victim->query("name"))
			quest_master = "shan";
			
		if ( ( quest_master == "" )
		&& ( quest = killer->query("quest/helian") )
		&& (int)killer->query("quest/helian/time") >= time()
		&& ( !killer->query("quest/helian/lock") )
		&& ( !killer->query("quest/helian/finished") )
		&& quest["quest"]==victim->query("name"))
			quest_master = "helian";
		
		if ( quest_master == "" )
			return;
						
		tell_object(killer,"恭喜你！你又完成了一项任务！\n");
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
		tell_object(killer,HIW"你被奖励了：" +
        	chinese_number(exp) + "点实战经验，"+
        	chinese_number(pot) + "点潜能，" +
        	chinese_number(score)+"点江湖阅历。\n" NOR);
        	
		quest_finished( killer, quest_master );        			
	}
}


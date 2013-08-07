// feixing-shu.c ∑…–« ı
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *dodge_msg = ({
	"$n◊Û“ªµ„”““ªªŒ£¨ÀÊº¥ªÿµΩ‘≠µÿ£¨«·«…µÿ∂„π˝¡À$N’‚“ª’–°£\n",
	"$nÃ⁄…Ì‘æ∆“ª∏ˆø’∑≠£¨≤¢À≥ ∆…¡µΩ“ª±ﬂ°£\n",
	"$n«·«·Õ˘≈‘±ﬂ“ª◊›£¨æÕ“—¿Î$N”–¡Àœ‡µ±µƒæ‡¿Î£¨$N’‚“ª’–◊‘»ª ß–ß°£\n",
	"$n»‡…Ì∂¯…œ£¨«·¡Èµÿ‘æπ˝$N£¨…¡µΩ¡À$Nµƒ±≥∫Û°£\n",
	"$n…Ì–Œº±…¡£¨–±œÚ«∞“ª≤Ω£¨æπ»ª“—æ≠∂„ø™¡À$Nµƒ’‚“ª’–°£\n",
	"$N—€«∞“ªª®£¨»¥º˚$næπ»ª“—¿Î◊‘º∫”– ˝’…÷Æ‘∂£¨»¥√ªº˚$n»Á∫Œ∂„π˝◊‘º∫µƒπ•ª˜µƒ°
£\n",
	"$N“ª∏ˆ≤ª¡Ù…Ò£¨$n“—√ª¡À◊Ÿ”∞°£$Nº±◊™…Ì£¨»¥º˚$n‘⁄ƒ«∂˘œÚ◊‘º∫’– ÷°£\n",
	"$N“ª’–π•≥ˆ£¨$n“—»ª≤ªº˚£¨$N√£»ªÀƒπÀ£¨»¥≤ªº˚$nµƒ”∞◊”£°\n",
});

mapping *action = ({
([	"action" : "$N«·…Ì∂¯ÕÀ£¨“ª’–°∫≥ı¬∂–«√¢°ª£¨ ÷÷–$wªØ◊˜“ªµ„∫Æ√¢…‰œÚ$n",	
	"damage": 130,
	"dodge" : 40,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 0,
	"skill_name" : "≥ı¬∂–«√¢"
]),
([	"action" : "$N”“ ÷Œ¢œÚ«∞“ª…Ï£¨ π≥ˆ°∫’ßº˚–«≥Ω°ª£¨ ÷¿Ô$wæ∂÷±…‰œÚ$nµƒÀ´—€",
	"damage": 40,
	"dodge" : 45,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 9,
	"skill_name" : "’ßº˚–«≥Ω"
]),
([	"action" : "$N“ª…˘«·–•£¨ ©’π≥ˆ°∫∫Æ“ππ¬–«°ª£¨…Ì–ŒŒ¢∂Ø£¨ ÷÷–$wæπ»ªœÚ…œ∑…\n∆»∆¡À∏ˆ»¶£¨ÀÊ∂¯—∏ÀŸœÆœÚ$nµƒ—¸º‰",
	"damage": 50,
	"dodge" : 40,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 18,
	"skill_name" : "∫Æ“ππ¬–«"
]),
([	"action" : "$N π“ª’–°∫–«π‚…¡À∏°ª£¨Õª»ª◊›…ÌœÚ∫Û“ª∏ˆ∑≠πˆ£¨æÕ‘⁄øÏ¬‰µÿµƒ“ªÀ≤º‰£¨$n∂∏»ª∑¢œ÷º∏µ„∫Æπ‚…¡À∏≤ª∂®µÿœÆœÚ◊‘º∫",
	"damage": 135,
	"dodge" : 55,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "‘˙…À",
	"lvl" : 27,
	"skill_name" : "–«π‚…¡À∏"
]),
([	"action" : "$N”“ ÷“ªª”£¨“ª’–°∫–«√¢≤ª∂®°ª£¨$n√˜√˜ø¥º˚$N ÷¿Ôµƒ$w“—…‰œÚ◊‘º∫µƒ–ÿ«∞¥Û—®£¨µΩ¡ÀΩ¸¥¶»¥Õª»ª◊™π•œÚ◊‘º∫µƒ∫Û–ƒ",
	"damage": 160,
	"dodge" : 50,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 36,
	"skill_name" : "–«√¢≤ª∂®"
]),
([	"action" : "$N≤ªº±≤ªª∫µÿ“ª∞´…Ì£¨ π≥ˆ°∫◊π¬‰÷Æ–«°ª£¨ ÷÷–$w∆Ω÷±µÿ…‰œÚ$nµƒ— ∫Ì£¨»¥”÷º”…œ∞µæ¢ π÷Æ÷–Õæ∏ƒœÚ£¨…‰œÚ$nµƒœ¬≈Ã",
	"damage": 140,
	"dodge" : 54,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 45,
	"skill_name" : "◊π¬‰÷Æ–«"
]),
([	"action" : "$NÃ⁄…Ì“ª‘æ∂¯∆£¨ ©’π≥ˆ°∫¿Ë√˜÷Æ–«°ª£¨ ÷¿Ôµƒ$w¥”…œÕ˘œ¬± ÷±µÿ…‰œÚ$nµƒÕ∑≤ø",
	"damage": 85,
	"dodge" : 10,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 54,
	"skill_name" : "¿Ë√˜÷Æ–«"
]),
([	"action" : "$N‘≠µÿ“ª∏ˆº±◊™…Ì£¨ÀÊº¥À´ ÷“ª∑˜£¨$wæÕ∆Æ∆Æ∫ˆ∫ˆµÿ∑…œÚ$n£¨‘≠¿¥’‚’– «°∫–«≥Ω”Œ¿Î°ª",
	"force":40,
	"damage": 110,
	"dodge" : 55,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 63,
	"skill_name" : "–«≥Ω”Œ¿Î"
]),
([	"action" : "$N π≥ˆ“ª’–°∫–«π‚∂Ÿ√°ª£¨«∞Ω≈“ª∂Â£¨ÀÊº¥∑≠…Ì∂¯∆£¨ ÷÷–$w≤ª¥¯Àø∫¡∑Á…˘»¥”÷—∏ÀŸŒﬁ±»µÿ…‰œÚ$nµƒ«∞–ÿ",
	"force":63,
	"damage": 120,
	"dodge" : 60,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 72,
	"skill_name" : "–«π‚∂Ÿ√"
]),
([	"action" : "$NÕª»ªÃ⁄…ÌœÚ∫Ûº±ÕÀ£¨ π≥ˆ°∫–«ø’’®¿◊°ª£¨À´ ÷œÚ«∞“ªÕ∆£¨ ÷¿Ô$wæÕ“˛“˛¥¯◊≈¿◊…˘º≤…‰œÚ$n",
	"force":70,
	"damage": 110,
	"dodge" : -5,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 81,
	"skill_name" : "–«ø’’®¿◊"
]),
([	"action" : "$N ©’π≥ˆ°∫"+HIW"–«ªÆ≥§ø’"NOR+"°ª£¨‘≠µÿ≤‡…Ì∑…∆£¨”“ ÷Œ¢Œ¢œÚ«∞“ª»˜£¨ ÷÷–$wª√◊˜“ªµ„∫Æπ‚≥ ‘≤ª°–Œ…‰œÚ$n",
	"force":90,
	"damage": 160,
	"dodge" : 50,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 90,
	"skill_name" : "–«ªÆ≥§ø’"
]),
([	"action" : "$NŒ¢Œ¢ƒ˝…Ò£¨ π≥ˆ°∫"+HIY"–«π‚ÕÚ’…"NOR+"°ª£¨…Ì”∞∆Æ∫ˆ≤ª∂®£¨$n∂Ÿæı Æ∑÷¥Ã—€£¨»¥º˚$N ÷¿Ôµƒ$w“—–Æ◊≈µÿ…œµƒ…≥ Ø“‘º∞÷‹Œßµƒ ˜“≥π•œÚ◊‘º∫",
	"force":100,
	"damage": 130,
	"dodge" : 65,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 99,
	"skill_name" : "–«π‚ÕÚ’…"
]),
([	"action" : "$N∫ˆ»ª«·Ãæ“ª…˘£¨◊™…Ì∂¯––£¨$n’˝≥Ÿ“…º‰£¨»¥º˚—€«∞“—æ° «$wµƒ”∞◊”£¨—€ø¥Œﬁ¥¶ø…∂„¡À£°÷ª≈¬’‚’–æÕ «°∫"+HIC"¬˙ÃÏ–«”Í"NOR+"°ª¡À£¨$n≤ª”…¥Ûæ™ ß…´",
	"force": 88,
	"damage": 120,
	"dodge" : 70,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "¥Ã…À",
	"lvl" : 110,
	"skill_name" : "¬˙ÃÏ–«”Í"
])
});

int valid_enable(string usage)
{
	return usage=="throwing" || usage=="dodge" || usage=="parry" || usage=="move";
}

int valid_learn(object me)
{
	if ((int)me->query_skill("huagong-dafa", 1) < 20)
		return notify_fail("ƒ„µƒªØπ¶¥Û∑®ª∫Ú≤ªπª£¨Œﬁ∑®—ß∑…–« ı°£\n");
	if ((int)me->query_skill("dodge", 1) < 20)
		return notify_fail("ƒ„µƒ«·π¶ª∫Ú≤ªπª£¨Œﬁ∑®¡ÏŒÚ∑…–« ı°£\n");
	if ((int)me->query_dex() < 25)
		return notify_fail("ƒ„µƒ…Ì∑®≤ªπª¡È«…£¨Œﬁ∑®¡ÏŒÚ∑…–« ı°£\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("ƒ„ π”√µƒŒ‰∆˜≤ª∂‘°£\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("ƒ„µƒÃÂ¡¶Ã´µÕ¡À°£\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("ƒ„µƒƒ⁄¡¶≤ªπª¡∑∑…–« ı°£\n");
	me->receive_damage("qi", 30);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	if(level >= action[i]["lvl"])
		return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("feixing-shu", 1);
	for(i = sizeof(action); i > 0; i--)
	if(level > action[i-1]["lvl"])
		return action[NewRandom(i, 20, level/5)];
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"feixing-shu/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("poison",1)) > 20)
	{
		victim->apply_condition("xx_poison", random(2) + 1 + victim->query_condition("xx_poison"));
	}
}

int help(object me)
{
	write(HIC"\n∑…–« ı£∫"NOR"\n");
	write(@HELP

    ∑…–« ı «–«Àﬁ≈…∞µ∆˜°£

	—ßœ∞“™«Û£∫
		ªØπ¶¥Û∑®20º∂
		ª˘±æ«·π¶20º∂
		∫ÛÃÏ…Ì∑®25
HELP
	);
	return 1;
}


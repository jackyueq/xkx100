// king-of-dragon.c ������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }
string river_go_msg() {return HIW"$N΢΢һЦ����ָ����һ�����ơ�������$N������ϣ�����ƮƮ�����԰���ȥ��\n";}
string river_come_msg() {return HIW"ֻ��$N���Żƽ�ս�ף���̤��ɫ���ƣ����ˮ�������\n";}

string *dodge_msg = ({
	HIY "$n����΢Ц����������ׯ��֮ɫ��$N���������ڵأ���Ĥ�ݡ�\n" NOR ,
	HIY "$n������ڣ�$N����ͷ�����ǣ�һͷ�Ե��ڵء�\n" NOR ,
});

mapping *action = ({
([	"action": HIR "$N�黨΢Ц������ӿ��һƬ��������$n" NOR ,
	"force" : 0,
	"dodge" : 0,
	"damage": 0,
	"lvl" : 0,
	"skill_name" : "��������",
	"damage_type": "ʥ��֮��"
]),
});

int valid_enable(string usage) 
{ 
	return usage == "sword" || usage == "dodge" || usage == "unarmed" || usage == "parry" || usage == "blade" || usage == "whip" || usage == "force" || usage == "claw" || usage == "spear" || usage == "dagger" || usage == "finger" || usage == "staff" ;
}

string query_skill_name(int level)
{
	int i;
	return action[0]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int i, level;
	return action[0];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[0];
}

int valid_learn(object me)
{	
	if ( ! wizardp(me))
	return notify_fail("�۵����񹦣���ֻ������ʦѧϰ��\n");
}

string exert_function_file(string func)
{
	return __DIR__"king-of-dragon/" + func;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if ( ! userp (victim)) if ( living (victim)) victim -> unconcious () ;
}

int help(object me)
{
	write(HIC"\n�����񹦣�"NOR"\n");
	write(@HELP

    ��ʦ�ڹ���

	ѧϰҪ��
		��ʦ
HELP
	);
	return 1;
}


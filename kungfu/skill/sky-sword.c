// ��������Դ��书����
// winder
// ���
// �һ�������������
// 20000000
// ����
// sword
// �콣





inherit SKILL;

/////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
	"action" :"$N�ڿ�Ծ��һ�С����족������$w����$n$l����һ��",
	"damage" :50,
	"dodge" :20,
	"parry" :20,
	"damage_type": "����",
	"skill_name" : "����"
]),
// ZHAOSHI :1

([
	"action" :"$N����һ�ᣬһ�С����족������$w�����ɨ��$n��$l",
	"damage" :80,
	"dodge" :10,
	"parry" :20,
	"damage_type": "����",
	"skill_name" : "����"
]),
// ZHAOSHI :2

([
	"action" :"$N�ż�һ�㣬һ�С����족������$w���϶�����$n��$l��ȥ",
	"damage" :100,
	"dodge" :10,
	"parry" :10,
	"damage_type": "����",
	"skill_name" : "����"
]),
// ZHAOSHI :3

([
	"action" :"$N���ֽ�ָһ����һ�С����족������$w��ת�����¶�����$n��$l��ȥ",
	"damage" :130,
	"dodge" :5,
	"parry" :10,
	"damage_type": "����",
	"skill_name" : "����"
]),
});
// ZHAOSHI :4
int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�콣"+"��\n");
	return 1;
}
int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
int effective_level()
{
	return 30;
}
int practice_skill(object me)
{
	object weapon; 
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");	
	if( (int)me->query("qi") < 40 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 40 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
} 
string *parry_msg = ({
	"$nʹ��һ�����У�����$v���һ�У�ͻȻ���л�ʽ����ס$n��ȫ��\n",
});
string *unarmed_parry_msg = ({ "$nһ�з����������е�$v������$N����ʽ��\n", });
string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{
	return -150;
}
int practice_bonus()
{
	return -150;
}
int black_white_ness()
{
	return 30;
}
string perform_action_file(string action)
{
	return CLASS_D("player") + "/"+"sword"+"/" + action;
}

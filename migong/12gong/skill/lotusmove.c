// lotusmove.c
// By Dream Dec. 18, 1996

inherit SKILL;

string *dodge_msg = ({
	"$n����һ�ݣ�ʹ�������������Ⱦ�������������ض㿪��$N��һ�С�\n",
	"$n��������ʹ����ӳ�պɻ�����$Nֻ������һ������ʧ$n����Ӱ��\n",
	"$nһ�С����ص�������$N��ǰ������������$n��$N��Ȼ�е������޴�ʹ��\n",
	"$n˫��һ�٣�һ�С�ͤͤ�������������ϱ�ֱ�ذ��𣬱��˿�ȥ��\n",
	"����$nʹһ�С���¶���������������Ʈ�����࣬�����ŵء�\n",
	"ֻ��$nһʽ���޾��������εض����ڰ����ת����ת��$N�Ĺ��ƾ�����ա�\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("����������������ܹ�ѧϰ��������\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�������������������������������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

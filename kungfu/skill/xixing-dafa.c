// xixing-dafa.c ���Ǵ�
// Last Modified by winder on Apr. 10 2000

#include <ansi.h>;
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("xixing-dafa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ���Ǵ󷨡�\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("ѧ���Ǵ󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
	if (!me->query("family") || me->query("family/master_id")!="ren woxing")
		return notify_fail("���Ǵ�ֻ�����ν���ѧϰ��\n");
	if (((int)me->query_skill("xixing-dafa", 1) < 20) &&
		((int)me->query_skill("xixing-dafa", 1) > 1) &&
		((int)me->query("max_neili") > 0))
		return notify_fail("��δ���������������޷�����ѧ���Ǵ󷨣�\n");

	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ���Ǵ���ʲ�ᣡ\n");

	if ( !me->query_skill("kuihua-xinfa",1))
		return notify_fail("�㲻��ѧ�����ķ�������ѧ���Ǵ󷨣���\n");

  return valid_public(me,"kuihua-xinfa");
}
int practice_skill(object me)
{
	return notify_fail("���Ǵ�ֻ����ѧ(learn)�������������ȡ�\n");
}

mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
  if ((int) me->query_skill("xixing-dafa", 1) < 70 ||
            ! living(me) 
            || victim->query_skill_mapped("force") == "taixuan-gong"
				)
                return;
    jiali=factor;
   if (jiali < 1 )
     return;

	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	switch (random(4))
                {
                case 0:
                        msg=BLU "$N" BLU "ֻ��������ԴԴ��к�����ɵô��һ����\n" NOR;
                        break;
                case 1:
                        msg=BLU "$N" BLU "ֻ���÷�������������ʯ���󺣣���֪���١�\n" NOR;
                        break;
                case 2:
                        msg=BLU "$N" BLU "ֻ���÷�������������Ӱ���٣���Ȼ��֪���䡣\n" NOR;
                        break;
                default:
                        msg=BLU "$N" BLU "��ס�߶�����������ֻ����$n���ƺ���������\n" NOR;
                        break;
                }

//if (dp/2+random(dp)<ap)  // ��ڤͬ�ȼ�1/2����
                           // ���� 1/3
	if (dp*3/4+random(dp)<ap)	//ͬ�ȼ�1/4����
	{

    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(ap/6+jiali));
    		if (me->query("neili") < me->query("max_neili") * 2)
        	{
           	me->add("neili", ap/6+jiali);
        	}
        	return msg;
        }
	}
	return 0;
}

string exert_function_file(string func)
{
	return __DIR__"xixing-dafa/" + func;
}

int help(object me)
{
	write(HIC"\n���Ǵ󷨣�"NOR"\n");
	write(@HELP

    ������̺�ľ�µ�һ���ڹ���

    ���Ǵ󷨴��Ա���������ң�ɣ���Ϊ��ڤ�񹦺ͻ�������
·�������Ӵ�����Ϻ������ɷֱ��䣬�϶�Ϊһ����Ϊ���Ǵ󷨡�
��Ҫ�Ǽ̳��˻�����һ·����ϰ�ߵ���ﳣ����䣬������ȣ�
����������ȿ���ˮ��������Ϣ��ɢ֮��������Ѩ��
    ���Ǵ�ֻ�ܰ�������Ϊʦѧϰ�������൱��Ե����ѧ����

	ѧϰҪ��
		�����ķ�
		�����ڹ�10��
		�����ٵ�����
		����ѧϰ�����ķ�
		ɢ��
HELP
	);
	return 1;
}


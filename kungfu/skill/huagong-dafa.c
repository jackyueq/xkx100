// huagong-dafa.c ������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("huagong-dafa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;

	if(me->query("family/family_name")!="������")
		return notify_fail("ֻ�����޵��Ӳ���ѧ�����󷨡�\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ�����󷨡�\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
	if ( me->query_skill("buddhism",1) )
		return notify_fail("������ͺ¿�ǵ��ķ�����ѧ��������ʲ�ᣡ\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"huagong-dafa/" + func;
}
/* �����жԷ��ĸ����ã�Ŀǰ��Ҫ�����ڹ��� factor= ���� damage_bonus=���� */
mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
  if ((int) me->query_skill("huagong-dafa", 1) < 70 ||
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
                        msg=HIB "$N" HIB "ֻ��������ԴԴ��к�����ɵô��һ����\n" NOR;
                        break;
                case 1:
                        msg=HIB "$N" HIB "ֻ���÷�������������ʯ���󺣣���֪���١�\n" NOR;
                        break;
                case 2:
                        msg=HIB "$N" HIB "ֻ���÷�������������Ӱ���٣���Ȼ��֪���䡣\n" NOR;
                        break;
                default:
                        msg=HIB "$N" HIB "��ס�߶�����������ֻ����$n���ƺ���������\n" NOR;
                        break;
                }

//if (dp/2+random(dp)<ap)  // ��ڤͬ�ȼ�1/2����
	if (dp*2/3+random(dp)<ap)	//ͬ�ȼ�1/3����
//������Դ�Ա�ڤ ���ö����ڹ�����ȱ�ڤ��
	{

//		message("vision",msg,environment(me));
    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(ap/6+jiali));
    		if (me->query("neili") < me->query("max_neili") * 2)
        	{
         //   	me->add("neili", ap/6+jiali);//����������������
        	}
        	return msg;
        }
	}
	return 0;
}
int help(object me)
{
	write(HIC"\n�����󷨣�"NOR"\n");
	write(@HELP

    ������ʦ������ԭΪ��ң��������֮ͽ�������Ӿ�ͨ��ڤ�񹦣�
��δ���붡����󶡴�����ʦ���ţ�ƾ�Ź��˵��ǻۣ����ձ�ڤ
�񹦵ľ��裬�Դ���һ�׻����󷨣��뱱ڤ�񹦸���ʤ�����ѷ���
����

	ѧϰҪ��
		�����ڹ�10��
		����ѧ�����ķ�
		��Ӧ������
HELP
	);
	return 1;
}


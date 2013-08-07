// beimin-shengong.c ��ڤ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int valid_enable(string usage) { return usage=="force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	int i, lvl = (int)me->query_skill("beiming-shengong", 1);

	if(me->query("family/family_name")!="��ң��")
		return notify_fail("ֻ����ң���Ӳ���ѧ��ڤ�񹦡�\n");
	if ( me->query_skill("force",1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����������ᱱڤ�񹦡�\n");
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ı�ڤ�񹦡�\n");
	return valid_public(me,"bahuang-gong");
}

int practice_skill(object me)
{
	return notify_fail("��ڤ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
/* �����жԷ��ĸ����ã�Ŀǰ��Ҫ�����ڹ��� factor= ���� damage_bonus=���� */
mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
	
	
	  if ((int) me->query_skill("beiming-shengong", 1) < 70 ||
            ! living(me) 
     	  || victim->query_skill_mapped("force") == "taixuan-gong"
				)
       return;
       if (!me->query("perform/shield") 
       && !SCBORN_D->valid_learn(me,"beiming-shengong"))
       return ;
   jiali=factor;
   if ( jiali <1 || victim->query("id")=="songyang" /*��������ľ�˿�������*/ )
      return;

	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	switch (random(4))
                {
                case 0:
                        msg=HIM "$N" HIM "ֻ��������ԴԴ��к�����ɵô��һ����\n" NOR;
                        break;
                case 1:
                        msg=HIM "$N" HIM "ֻ���÷�������������ʯ���󺣣���֪���١�\n" NOR;
                        break;
                case 2:
                        msg=HIM "$N" HIM "ֻ���÷�������������Ӱ���٣���Ȼ��֪���䡣\n" NOR;
                        break;
                default:
                        msg=HIM "$N" HIM "��ס�߶�����������ֻ����$n���ƺ���������\n" NOR;
                        break;
                }

	if (dp/2+random(dp)<ap )
	{

//		message("vision",msg,environment(me));
    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(jiali+ap/6));
    		if (me->query("neili") < me->query("max_neili") * 2)
          	me->add("neili", ap/6+jiali);
      	return msg;
        }
	}
	return 0;
}

string exert_function_file(string func)
{
	return __DIR__"beiming-shengong/" + func;
}
int help(object me)
{
	write(HIC"\n��ڤ�񹦣�"NOR"\n");
	write(@HELP

    ��ڤ��Ϊ��ң�������ڹ���
    ׯ�ӡ���ң�Ρ����ƣ����֮����ڤ���ߣ����Ҳ�������ɣ�
�����ǧ�δ��֪����Ҳ�������ƣ����ҷ�ˮ֮��Ҳ��������
������Ҳ����������ˮ������֮�ϣ����Ϊ֮�ۣ��ñ����򽺣�ˮ
ǳ���۴�Ҳ�����ǹ���ң���书���Ի�������Ϊ��һҪ�塣������
�������书�޲�Ϊ�����ã���֮��ڤ������С���޲��أ�����С
���޲��ݡ��ǹ�����Ϊ��������Ϊĩ����ڤ��ϵ������֮������
Ϊ���С���ڤ��ˮ���������������ƣ��ٴ��㺣����֮ˮ���ݰ�
�����á�����޽������ڻ��ۡ�
    �����������������Ŷ������̣�����ң�����������֮����
���̶������ţ�Ĵָ������ӣ���֮�������������������ŵ���
Ѩ��Ȼ��֮������ʤ���ң���ˮ������뽭�ӣ�����Ī������ң
����֧��δ��Ҫ����Ω��������������������Ϊ���ã�����ȡǧ��
������֮�ڵأ�������������Ҳ��

	ѧϰҪ��
		�����ڹ�10��
		̫���޷�ѧ��50�����ϵı�ڤ��
HELP
	);
	return 1;
}


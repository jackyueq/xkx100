// exert.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string force,pfarg,sarg,uarg;
	string target;
	string temp,temp1;
	object *ob;
	int result,i;
	
	seteuid(getuid());
        ob = all_inventory(environment(me));       
	
        if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");

	if( !arg ) 
		return notify_fail("��Ҫ���ڹ���ʲô��\n");
		
	if( arg=="roar" && (string)environment(me)->query("short") == "��̨")
		return notify_fail("��̨�ϲ��������ڹ����õġ�\n");

	if( stringp(force = me->query_skill_mapped("force")) )
	{
		notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");
		if (me->query_temp("lonely-sword/poqi"))
		{
			me->delete_temp("lonely-sword/poqi");
			me->start_busy(2);
			message_combatd(HIR"$N����������������������Ϣһ�����ң������޷����ơ�\n"NOR,me);
			return 1;
		}
		if( SKILL_D(force)->exert_function(me, arg) ) 
		{
			if( random(120) < (int)me->query_skill("force") &&
				(int)me->query_skill("force",1)<200)
				me->improve_skill(force, 1, 1);
			return 1;
		} 
		else if( SKILL_D("force")->exert_function(me, arg) ) 
			{
				if(random(120) < (int)me->query_skill("force",1)
					&& (int)me->query_skill("force",1)<200)
					me->improve_skill("force", 1, 1);
				return 1;
			}
		return 0;
	}

	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��ڹ���\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��exert | yun <��������> [<ʩ�ö���>]
          exert | yun <�ڹ���;>

    ����������һЩ���칦�ܣ������Ҫָ��<��������>��<ʩ�ö���>���
�п��ޡ�����ʹ��ĳһ���ڹ������칦��֮ǰ����������� enable ָ����
ָ����Ҫʹ�õ��ڹ���

    ��ο� help force��help neigong �ɵ�֪һЩ�󲿷��ڹ����еĹ��ܣ�
���������õ��ڹ�������û�иù��ܣ���һ�Ի�ο�����˵����֪��

ע�������ı��Լ����ڹ�����ԭ�����������������ֱ��ת����ȥ������
    �ӣ���ʼ��

HELP
        );
        return 1;
}

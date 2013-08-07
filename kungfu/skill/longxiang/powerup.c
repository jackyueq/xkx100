// powerup.c ���๦����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;
	int i,lx,num;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/longxiang/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( target != me )
		return notify_fail("��ֻ�������Լ���ս������\n");
	if( (int)me->query("neili")<200)
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
/*
    �����������������ʮ���㣬��һ�㹦��ʮ��ǳ�ף���������
֮�ˣ�ֻҪ�õ����ڣ�һ�����м������ɡ��ڶ���ȵ�һ�����һ
������ʱ�����ꡣ�������ֱȵڶ������һ������ʱ�߰��ꡣ���
�ɱ�������Խ������Խ�ѽ�չ������������Ժ���������һ�㣬
����������ʮ�����Ͽ๦��
һ�� 2 
���� 4
��   8
��   16
��   32
��   32
��   32
��   32

*/
	lx = me->query_skill("longxiang",1);
	for(num=0,i=0;i<13;i++)
	{
		if (lx < 0) break;
		switch(i)
		{
			case 0: lx -= 2;num++;break;
		  case 1: lx -= 4;num ++;break;
		  case 2: lx -= 8;num ++;break;
		  case 3: lx -= 16;num ++;break;
		  default : lx -= 32;num ++;break;
		}
	}

//	message_combatd(HIR"$N���һ����ȫ������ڽڱ��죬һ��Ѹ�͵������������ɢ������\n"NOR, me);
	message_combatd(HIR"$N����Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ������"+chinese_number(num)+"��"+chinese_number(num)+"��֮����\n"NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("powerup") )
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/dodge", - amount);
		me->delete_temp("powerup");
		tell_object(me, "������������������ϣ��������ջص��\n");
	}
}
int help(object me)
{
	write(WHT"\n���������֮������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��Ĺ�����������

	����Ҫ��
	        ����200
HELP
	);
	return 1;
}


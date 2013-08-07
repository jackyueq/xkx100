// kungfu/skill/taixuan-gong/taixuan
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
   int skill;
   if ( userp(me) && !wizardp(me) && 
//  !me->query("perform/taixuan") &&
  !me->query("can_perform/taixuan-gong/taixuan") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

   if( target != me ) 
      return notify_fail("��ֻ�ܶ��Լ���["+HIW+"����̫��"+NOR+"]\n"NOR,);
	 if ((int)me->query_skill("taixuan-gong", 1) < 100)
		  return notify_fail("���̫����̫���ˡ�\n");
   if( (int)me->query("neili") < 100 ) 
  	  return notify_fail("�������������\n");
   if( (int)me->query_temp("powerup") ) return
       notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("taixuan-gong",1);

        me->add("neili", -100);
        me->receive_damage("qi",0);

        message_combatd(
HIW"$NͻȻһ������������������һ��ʫ��������ϸ��֮�²��ɴ�!!!!!\nԭ�����Ȼ���Ǵ�˵�е������湦������̫��������\n" NOR, me);
        me->add_temp("apply/attack", skill/3);
        tell_object(me,HIR"��Ĺ����������!\n"NOR);
        me->add_temp("apply/dodge", skill/3);
        tell_object(me,HIR"��ķ����������!\n"NOR);
        me->set_temp("powerup", 1);
        me->add_temp("apply/strength",skill/40);
        tell_object(me,HIG"������������!\n"NOR);
        me->add_temp("apply/dexerity",skill/40);
        tell_object(me,HIG"����ٶ������!\n"NOR);
        me->add_temp("apply/constitution",skill/40);
        tell_object(me,HIG"��ĸ��������!\n"NOR);
        me->add_temp("apply/intelligence",skill/40);
        tell_object(me,HIG"������������!\n"NOR);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int skill)
{
        me->add_temp("apply/attack", - skill/3);
        me->add_temp("apply/dodge", - skill/3);
        me->delete_temp("powerup");
        me->add_temp("apply/strength",- skill/40);
        me->add_temp("apply/intelligence",- skill/40);
        me->add_temp("apply/constitution",- skill/40);
        me->add_temp("apply/dexerity" , - skill/40);
        tell_object(me, "���"+HIW+"������̫����"+NOR+"������ϣ��������ջص��\n");
}
int help(object me)
{
		write(WHT"\n̫����֮������̫������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���ӹ�������������
		��ʱ����������������ԡ����ǡ���

	����Ҫ��
		�����͵�ʯ�ڲ���
		̫����100��
		����100
HELP
	);
	return 1;
}

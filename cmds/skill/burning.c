// burning.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int count;

        if (me->query_temp("burning_up"))
                return notify_fail("����������ŭ���У�û�б�Ҫ�ٷ���һ�Ρ�\n");

        if (me->query("nuqi") < 1000)
                return notify_fail("�����ڻ�������ŭ���޷����Լ�ŭ��ȼ�ա�\n");

        message_vision(HIR "$N" HIR "һ�������Ŀ��ʱ����"
                       "���䣬���ͱ��ˣ��Ʋ��ɵ���\n" NOR, me);

        me->add("nuqi",- (500 + random(300)));
        count = me->query_skill("force") / 5;
        me->set_temp("burning_up", count);
        me->add_temp("apply/attack", count);
        me->apply_condition("burning", 1);

	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: burning|fennu
 
���ָ�����㽫���ڽ�����ķ�ŭ��й�������������Գ�ֵ�������
�Ĺ����������ڷ�йʱ�᲻�ϵ�������ķ�ŭ��ֱ������ƽ����ʱ��
���Զ��ָ���

HELP
        );
        return 1;
}

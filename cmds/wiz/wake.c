// wake.c

#include <ansi.h>;
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object target;

	if(!arg || !objectp(target = present(arg, environment(me))))
		return notify_fail("���뻽��˭��\n");
	if(target == me)
		return notify_fail("�㲻���Լ������Լ���\n");
	message_vision(HIY "$N������$n��ͷ������������װ���ˣ���������\n$n�����۾�һ��������˼��վ��������\n" NOR, me, target );
	target->receive_curing("qi", 10 );
	target->remove_call_out("revive");
	target->revive();
	target->reincarnate();
 
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wake <����>
 
���ѻ���
 
HELP
    );
    return 1;
}

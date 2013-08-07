// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

	if( me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");
	if( environment(me)->query("no_ansuan") )
		return notify_fail("�����ֹս����\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");
	if( !arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");
	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");
	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");
	if( !living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "�Ѿ��޷�ս���ˡ�\n"); 
	if(obj==me) return notify_fail("�㲻�ܹ����Լ���\n");

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me )
	{
		message_vision("\n$N����$n˵����" + RANK_D->query_self(me) + me->name() + "�����" + RANK_D->query_respect(obj) + "�ĸ��У�\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL"�����Ը��ͶԷ����б��ԣ�����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� fight ָ�\n" NOR);
		write(YEL"���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
		return 1;
	}
	if( obj->query("can_speak") )
	{
		message_vision("\n$N����$n˵����" + RANK_D->query_self(me) + me->name() + "�����" + RANK_D->query_respect(obj) + "�ĸ��У�\n", me, obj);
		notify_fail("������" + obj->name() + "��������������\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : fight <����>

    ���ָ��������һ������ֽ̡������ǡ��д����ա���������ʽ��ս��
�����ǵ㵽Ϊֹ��ֱ����һ���������͵�һ��Ϊֹ�����ֻ����������������
������ˣ����ǲ��������еģΣУö�ϲ����ܣ���������״������ı���
Ҫ��ᱻ�ܾ�������Է���Ը����������ս������Ȼ����ǿ���ã�������
�����ȵ�ָ�ʼս���������������ָ��������ʧ��Ҳ�ᵼ��ս
������Ҫע����Ƕ����Ϊ��ͨ���ԣ��������ǻ���κι���ʩ�������Ա�
����������ද���ǹ����Եģ�����˾�ɱ��
 
�������ָ��: kill, hit

    ����Է���Ը����������ս������Ȼ����ֱ���� kill ָ�ʼս����
HELP
	);
	return 1;
}
 

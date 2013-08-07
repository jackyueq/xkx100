// /cmds/std/hit.c

// Modified by Constant Jan 15 2001

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

	if(me->query("id") != obj->query_temp("bt_ownname") && me->query_temp("bt/working"))
		return notify_fail("����Ϊ���죬ִ�й��񣬿ɲ���ɱ��ð����\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( me->is_fighting(obj) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( me->query_temp("hitting") )
		return notify_fail("���ͣ����ͣ����ͣ�\n");
/*
	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��������㻹Ҫ�򣬹����˵�ɣ�\n"); 
*/

	if(obj==me)	return notify_fail("���Լ�������ô�벻����\n");

	if((int)obj->query("age") <= 15 && userp(obj))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

	if( userp(obj) ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
		me->set_temp("hitting");
		remove_call_out("do_hit");
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	// hit��friendly��npc�Զ�����kill״̬��
	// Modified by Constant Jan 15 2001
	if( obj->query("can_speak") && obj->query("attitude") == "friendly" ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
/*
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�����"
			+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);

		notify_fail("������" + obj->name() + "��������������\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;
*/

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : hit <����>
 
���ָ������ֱ����һ��������С���������ʽ��ս���Ǽ�ʱ�ģ�ֻҪ���һ
��������ս���ͻῪʼ��ֱ��ĳһ������50% ����Ϊֹ�����ָ�����Щ��
ϲ��fight��NPC�����ã���Ϊ�ܶ�ʱ����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: fight, kill

HELP
    );
    return 1;
}
 

// Filename : /cmds/std/ride.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit F_CLEAN_UP;

int do_ride(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, env;

	if( !arg ) return notify_fail("��Ҫ��ʲô������\n");
	if( me->query_temp("is_riding") )
		return notify_fail("���Ѿ��������ˣ�\n");
	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if( me->is_fighting() )	return notify_fail("�㻹��ս���У�û������ȥ��\n");

	// Check if a container is specified.
	env = environment(me);

	if( !objectp(obj = present(arg, env)) || !living(obj) )
		return notify_fail("����û�������������\n");
	if( !obj->query("ridable") &&
		obj->query_temp("owner") != me->query("id") )
		return notify_fail("���������ҲҪ��������ƨ�ɣ�\n");
	if( !living(obj) || obj->query_temp("noliving"))
		return notify_fail("��������Լ����ε��ˣ�����ô�\n");
	return do_ride(me, obj);
	write("����ȥ�ˡ�\n");
}
	
int do_ride(object me, object obj)
{
	object old_env, *guard;

	if( !obj ) return 0;

	if( guard = obj->query_temp("guarded") )
	{
		guard = filter_array(guard, (: objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2) :), me);
		if( sizeof(guard) )
			return notify_fail( guard[0]->name() + "������" + obj->name() + "һ�ԣ���ֹ�κ������ߡ�\n");
	}

	if( obj->move(me) )
	{
		message_vision("$N�߽�$n������������ȥ�����ֺ��ǽýݡ�\n", me, obj );
		obj->set_temp("is_rided_by", me);
		me->set_temp("is_riding", obj);
//�ﶯ����������������
/*
		if(obj->query("dex"))
			me->set_temp("apply/dexerity", obj->query("dex")/3);
		if(obj->query("str"))
			me->set_temp("apply/strength", obj->query("str")/3);
*/
	}
	else
	{
		message_vision("$N���ϴ��Ķ���̫���ˣ��޷��ﵽ$n����ȥ��\n", me, obj );
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : ride <������>
 
    ���ָ������������ϴ�������ѱ���Ķ��

    �����Ѿ�ѱ���Ķ�����Խ�������ָ�

����ָ�
        come <������>:                  �ö�����������ж���
        stay:                           ֹͣ����ĸ���״̬��
        attack <ĳ��>:                  �ö��﹥�����ˡ�
        stop <������>:                  �ö���ֹͣ���˵Ĺ�����
        release:                        ������ū״̬����������롣

����ָ���ֻ��ĳЩ�������ã�
        ride <������>:                  ���������������ȡ�
        unride <������>:                �£��뿪���
        feed <����> to <������>:        �涯��ιʳ��
        imbibe <������>:                ��������ˮ��

HELP
	);
	return 1;
}


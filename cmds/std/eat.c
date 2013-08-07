// Last Modified by Winder on May. 15 2001
// eat.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;

	if(!living(me) || me->query_temp("noliving") ) return 1;
	if(me->query("jing")<0 || me->query("qi")<0 )
		return notify_fail("��̫���ˣ�ʵ��û������ʲô�ˡ�\n");
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg) return notify_fail("��Ҫ��ʲô������\n");
	if(!objectp(obj = present(arg, me)) )
	{
		if(objectp(obj = present(arg, environment(me))) &&
			!obj->is_character())
			tell_room(environment(me), me->name() + "���ŵ��ϵ�"+obj->name() + "������һ����ĭ��\n",({ me }));
		return notify_fail("������û������������\n");
	}
	if(!obj->query("food_supply") )
		return notify_fail("������㣬�ⶫ���ܳ���\n");
	if(!obj->query("food_remaining") )
		return notify_fail( obj->name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");
	if( me->query("food") >= me->max_food_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
		
	me->add("food", obj->query("food_supply"));
	if( obj->query("eat_func") ) return 1;
	if( !obj ) return 1;
	
	obj->set("value", 0);
	obj->add("food_remaining", -1);
	if((int)obj->query("food_busy"))
		me->start_busy(obj->query("food_busy"));
		
	if( !obj->query("food_remaining") )
	{
		obj->delete_temp("apply/long");
		if((string)obj->query("finish_msg"))
			message_vision(obj->query("finish_msg"), me, obj);
		else message_vision("$N��ʣ�µ�$n�Եøɸɾ�����\n", me, obj);
		if( !obj->finish_eat() ) destruct(obj);
	} 
	else
	{
		if((string)obj->query("eat_msg"))
			message_vision(obj->query("eat_msg"), me, obj);
		else message_vision("$N����$nҧ�˼��ڡ�\n", me, obj);
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : eat | chi <��Ʒ����>
 
    ���ָ����ǳԣ��������ĵ�ʳ���Ҫע����Щʳ������Ǵ����ġ�
 
HELP
	);
	return 1;
}
 

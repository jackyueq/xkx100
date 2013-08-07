// Filename : /cmds/std/feed.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, pet;
	string owner, food, ob;
	int i, j, lvl, effect;

	seteuid(getuid());

	if(!arg || sscanf(arg, "%s to %s", food, ob) !=2)
		return notify_fail("��Ҫιʲô������˭��\n");
	if(!objectp(obj = present(food, me)) ) 
		return notify_fail("������û��������������\n");
	if(!objectp(pet = present(ob, environment(me))) || !living(pet))
		return notify_fail("����û�������Ķ��\n");
	if(pet->query("race") == "����" )
		return notify_fail(pet->name()+"�ǳ���ô���ɴ��۾�������\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"��æ���أ��ĳԵ���ʲô��\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"��æ���أ��ĳԵ���ʲô��\n");
	if(me->is_busy() )
		return notify_fail("����æ���أ�ʲôҲ�����ˣ�\n");
	if(pet->is_fighting() )
		return notify_fail("�����ڴ���أ����ѵ�û��������\n");
	if(me->is_fighting() )
		return notify_fail("һ�ߴ��һ��ιʳ�������ǻ����ˣ�\n");
	if(!wizardp(me) && pet->query_temp("feeded"))
		return notify_fail("��һ�β��ܶ�Զ������Զ��˻������ӣ�"+pet->query("name")+"Ҳһ����\n");
	if((string)me->query("id")!=(string)pet->query_temp("owner"))
		return notify_fail("�㿴��"+pet->query("name")+"��ǰ�������£����һ���߿��ˡ�\n");
	if(!obj->query("siliao_supply") )
		return notify_fail("�ƺ�"+pet->query("name")+"������������Ȥ����\n");
	if(!obj->query("siliao_remaining") )
		return notify_fail( obj->name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");
	if(pet->query("food") >= pet->max_food_capacity() )
		return notify_fail(pet->name()+"�Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
	obj->set("value", 0);
	obj->add("siliao_remaining", -1);
	me->start_busy(1);
// ����ʳ��״̬�ı䡣
	pet->add("food", obj->query("siliao_supply"));
// ��ʱ��ʳ�����������ԡ��ճ���Ҳ�����ó����˳�������������ι76��ﵽ100����
// 9����Դﵽ50����
	pet->set_temp("feeded","1");
	call_out("del", 20, pet);
// ������������ѱ���޹ء�
	if(pet->query("owner") == me->query("id")) 
	{
// ʳ�����øı䣬�ۼ��Ա�������
		if(obj->query("siliao_effect"))
			pet->add("feed", obj->query("siliao_effect"));
// ι�������顣
		pet->add("combat_exp", 5+random(10));
		i = pet->query("feed");
		j = pet->query("level");
		if(i>=2+j*j)
		{
			tell_object(me, HIY"��ι����һ��ʳ��󣬷���"+pet->query("name")+"�ƺ��Եø�ǿ����Ҳ�������ˣ�\n"NOR);
// ι��������
			pet->add("level",1);
			pet->set("feed",0);
// ι����ѱ���ȡ�
			pet->add("obe", 1);
			lvl=pet->query("level");
		}
		pet->add("max_qi", lvl);
		pet->add("max_jing", lvl);
	}
	if( !obj->query("siliao_remaining") )
	{
		obj->delete_temp("apply/long");
		if((string)obj->query("finish_msg"))
			message_vision(obj->query("finish_msg"), pet, obj);
		else
		{
			message_vision( "$N�ó�һ"+obj->query("unit")+obj->query("name")+"������$n�������֡�\n$n��ѱ˳�����˹�ȥ��һ�ѵ�����"+obj->query("name")+"�����˸��ɸɾ�����\n", me, pet);
		}
		if( !obj->finish_eat() ) destruct(obj);
	} 
	else
	{
		if((string)obj->query("eat_msg"))
			message_vision(obj->query("eat_msg"), pet, obj);
		else 
			message_vision( "$N�ó�һ"+obj->query("unit")+obj->query("name")+"������$n�������֡�\n$n��ѱ˳�����˹�ȥ��һ�ѵ�����"+obj->query("name")+"���ݺݾ���һ�ڡ�\n", me, pet);
	}
	if( !obj ) return 1;
	
	return 1;
}

void del(object pet)
{
	pet->delete_temp("feeded");
}

int help(object me)
{
	write(@HELP
ָ���ʽ : feed <����> to <������>

    ��ָ�������ι������ѱ���Ķ��

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


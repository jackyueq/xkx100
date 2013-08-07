// Filename : /cmds/std/imbibe.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *obj, pet;
	string owner;
	int i, j, lvl;

	seteuid(getuid());

	if(!arg || arg == " ")
		return notify_fail("��Ҫ��˭ιˮ��\n");
	if(!objectp(pet = present(arg, environment(me))) || !living(pet))
		return notify_fail("����û���⶯�\n");
	if(pet->query("race") == "����" )
		return notify_fail(pet->name()+"�ǳ���ô���ɴ��۾�������\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"��æ���أ��ĺȵ���ʲô��\n");
	if(me->is_busy() )
		return notify_fail("����æ���أ�ʲôҲ�����ˣ�\n");
	if(pet->is_fighting() )
		return notify_fail("��û���������ڴ���𣿣�\n");
	if(me->is_fighting() )
		return notify_fail("һ�ߴ��һ��ιˮ�������ǻ����ˣ�\n");
	if((string)me->query("id")!=(string)pet->query_temp("owner"))
		return notify_fail("�㲻��"+pet->query("name")+"�����ˣ��˼Ҳ�������ġ�\n");
	if(pet->query("water") >= pet->max_water_capacity() )
		return notify_fail(pet->name()+"�Ѿ��ȵ�̫���ˣ���Ҳ�಻���κζ����ˡ�\n");

	me->start_busy(1);
	if(environment(me)->query("resource/water") )
	{
		if((string)pet->query("drink_msg"))
			message_vision(pet->query("drink_msg"), pet);
		else message_vision("$N�쳤��ͷ������ˮ�棬һ��������������ȥ��\n", pet);
		pet->add("water", 30);
	}
	else
	{
		obj = all_inventory(environment(me));
		for (i = 0; i < sizeof(obj); i++)
		{
			if(obj[i]->query("liquid/remaining") )
			{
				break;
			}
		}
		if( i == sizeof(obj) )
			return notify_fail("����ûɶ�������Ը�"+pet->name()+"ιˮ��\n");
// ������ˮ״̬�ı䡣
		pet->add("water", 10+obj[i]->query("liquid/drunk_apply"));
// ���������ı䡣
		obj[i]->add("liquid/remaining", -1);
// �ԵĲ�busy��ι��busy��feed.cҲһ����
		if((int)obj[i]->query("liquid/busy"))
			me->start_busy(obj[i]->query("liquid/busy"));
		if(obj[i]->query("liquid/remaining"))
			message_vision("$N�쳤��������$n���������µغ��˼���"+obj[i]->query("liquid/name")+"��\n", pet, obj[i]);
		else
			message_vision("$N�쳤��������$n���������¾Ͱ�"+obj[i]->query("liquid/name")+"���˸����⡣\n", pet, obj[i]);
// �ȵ���ҩ����
		if( obj[i]->query("liquid/poisontime") > 1 )
		{
			pet->apply_condition(obj[i]->query("liquid/poison"), obj->query("liquid/poisontime") );
			write(pet->query("name")+"ͻȻ���ú����ܵ�Ť�������������£�����ȵĶ����е㲻�Ծ���\n");
		}
// �ȵ�������
		switch(obj[i]->query("liquid/type"))
		{
			case "alcohol": pet->apply_condition("drunk",(int)pet->query_condition("drunk")+ (int)obj[i]->query("liquid/drunk_apply"));
					break;
		}
	}

// ������������ѱ���޹ء�
	if(pet->query("owner") == me->query("id")) 
	{
// ʳ�����øı䣬�ۼ��Ա�������
		pet->add("feed", 1);
		i = pet->query("feed");
		j = pet->query("level");
		if(i>=2+j*j)
		{
			tell_object(me,HIY"��ι����һ����ˮ�󣬷���"+pet->query("name")+"�ƺ��������ˣ�\n"NOR);
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

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : imbibe <����>

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


// yubee.c

#include <condition.h>;
#include <ansi.h>;
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object bee;
	string *msg=({
HIR"\n$N�����㵸����׽סһֻ"HIW"���"HIR"�������һ�����ַɿ��ˡ�\n",
HIW"\n���"HIY"һ�������һ��һ�����ɢ������$Nͷ������������\n",
HIW"\n���"HIC"��Ȼһ���Ӷ������ˣ�$N�ż�����������ҳ�����ȴ��ôҲ�Ҳ��š�\n",
HIW"\n���"HIM"�ڷ��裡������Ʈ��Ļ����У�����������������ߣ����������Ŀ�⡣\n",
	});
	if( !duration || !me->query_temp("marks/bee1"))
	{
		me->apply_condition("yubee", 0);
		return 0;
	}
	if(duration == 1)
	{
		me->reincarnate();
		message_vision(HIY"����˵�һ���ɻط䳲���档$Nϲ������ȥȡ���ˡ�\n"NOR,me);
		me->set_temp("marks/bee1",0);
//		bee=present("yu bee", environment(me));
//		destruct(bee);
		me->set_temp("marks/getmi",1);
		me->set_temp("marks/mihave",1);
		me->add_temp("marks/mi",1);
		return 0;
	}
//	if(me->query_temp("marks/bee1") && present("yu bee", environment(me)))
	{
		message_vision(msg[random(4)]+NOR,me);
	}
//	if(!present("yu bee", environment(me))) me->apply_condition("yubee", 0);
	me->apply_condition("yubee", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "job";
}


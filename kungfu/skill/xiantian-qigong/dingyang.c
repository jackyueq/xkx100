// dingyang.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/dingyang") &&
  !me->query("can_perform/xiantian-qigong/dingyang") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");
	if( me->is_fighting() ) return notify_fail("ս����������������\n");

	if(me->query("class") != "quanzhen")
		return notify_fail("�㲻����������֮ʿ���޷����Ƶ�ҩ��\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(me->query_condition("quanzhen_drug")>0)
		return notify_fail("��սӴ���ҩ���ã�����������\n");
	if((int)me->query_skill("xiantian-qigong", 1) < 100)
		return notify_fail("�������������Ϊ��������\n");
	if((int)me->query("neili") < 400) 
		return notify_fail("�������������\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("�����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "����������ʼ�˹����Ƶ�ҩ��\n" NOR);
	message("vision",
		HIW + me->name() + "��������������ʼ���Ƶ�ҩ��\n" NOR,
		environment(me), me);
	me->add("neili", -300);
	me->set("jiali", 0);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"mess",me :),5);
	me->apply_condition("quanzhen_drug", 20);
	return 1;
}
void mess(object me)
{
	object ob;
	if (random(10) > 6)
	{
		seteuid(getuid());
		ob=new("/clone/medicine/nostrum/dingyangdan");
message_vision("$N��ϥ���������ƺ�ʮ���������Ʒ���¶��һ�߻��Ĺ�â����һ��
"+HIY"���Ŷ�����"NOR+"ž��һ��������ϥ�ϡ�\n",me);
		ob->move(me);
	}
	else
	{
message_vision("$N��ϥ���������ƺ�ʮ��������ͷ������һ����������亹��������
ί���ڵء����۰���\n",me);
	}
	return;
}

int help(object me)
{
	write(WHT"\n��������֮����"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�������Ŷ�����

	����Ҫ��
		��������100��
		����400
		��Ϊȫ�����µ�ʿ
HELP
	);
	return 1;
}


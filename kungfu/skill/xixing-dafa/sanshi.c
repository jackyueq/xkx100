// sanshi.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
/*  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/sanshi") &&
  !me->query("can_perform/xixing-dafa/sanshi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");*/
	if( me->is_fighting() ) return notify_fail("ս����������������\n");

	if(me->query("family/master_id") != "ren woxing")
		return notify_fail("�㲻���ν����ĵ��ӣ��޷����Ƶ�ҩ��\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");
	if((int)me->query_skill("xixing-dafa", 1) < 100)
		return notify_fail("������Ǵ���Ϊ��������\n");
	if((int)me->query_skill("kuihua-xinfa", 1) < 100)
		return notify_fail("��Ŀ����ķ���Ϊ̫�͡�\n");
	if((int)me->query("qi") < 300) 
		return notify_fail("�����������\n");
	if((int)me->query("neili") < 400) 
		return notify_fail("�������������\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("�����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "����������ʼ�˹����Ƶ�ҩ��\n" NOR);
	message("vision",
		HIW + me->name() + "�������Ǵ󷨿�ʼ���Ƶ�ҩ��\n" NOR,
		environment(me), me);
	me->add("neili", -300);
	me->add("max_neili", -10);
	me->set("jiali", 0);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"mess",me :),5);
	return 1;
}
void mess(object me)
{
	object ob;
	int now_qi = me->query("eff_qi");
	message_vision("$N��ϥ������������ָ���˸�����������ͷ������һ����������亹�����ۣ�\n",me);
	me->receive_wound("qi", now_qi - 30);
	me->set("qi", me->query("eff_qi"));
	if (random(10) > 6)
	{
		seteuid(getuid());
		ob=new("/clone/medicine/nostrum/sanshi");
		message_vision("$N������ʬ�����ˡ�\n",me);
		ob->set("owner", me->query("id"));
		ob->move(me);
	}
	else
		message_vision("$N�������ˡ�û������ʬ�����ˡ�\n",me);
	return;
}

int help(object me)
{
	write(WHT"\n���Ǵ�֮��ʬ"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		������ʬ����
		���Ǵ����Ƶ���ʬ���񵤣�Ϊ���µ�һ��ҩ���ж���
		������������ȫ�����������Ƿ�߷���һ��䡣
		��help cuifa

	����Ҫ��
		�����ķ�100��
		���Ǵ�100��
		����400
		��Ѫ300
		��Ϊ�����еĵմ�����
HELP
	);
	return 1;
}


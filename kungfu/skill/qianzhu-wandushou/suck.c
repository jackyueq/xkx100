// suck.c
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��ȡ����"
int perform(object me,object target)
{
	int sp, dp,temp;
	int my_skill,my_force,tg_age,skill_count,duli;

	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

  if( !objectp(target) || target->query("host_id") != me->query("id") )
		return notify_fail("��Ҫ��ȡʲô����Ķ��أ�\n");

	if( target->query("age") < 99 )
		return notify_fail("�㿴����㣬�Ƕ������Ƕ�����\n");
	my_skill = (int)me->query_skill("qianzhu-wandushou", 1);
	my_force = (int)me->query_skill("wudu-shengong", 1);
	tg_age = (int)target->query("age");

	if( my_skill < 50 )
		return notify_fail("���ǧ�����ֻ��̫ǳ������������ȡ���أ�\n");
	if( my_force < 50 )
		return notify_fail("����嶾�񹦻��̫ǳ������������ȡ���أ�\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ�������ǧ�����֣�\n");
	if( me->is_fighting() )
		return notify_fail("ս�����޷�����ǧ�����֣�\n");
	if( me->is_busy() )
		return notify_fail("����æ���أ�\n");
	if( target->is_fighting() || target->is_busy() )
		return notify_fail("������æ���أ����ܺ�����ϣ�\n");
	if( me->query_temp("wudu_suck") )
		return notify_fail("�����������У�\n"); 
	if( my_skill > 100 && my_skill < 160 && tg_age < 999 )
		return notify_fail(target->query("name")+"�Ķ���������˵�Ѿ�̫��΢�ˣ�\n");
	if( my_skill > 159 && tg_age < 9999 )
		return notify_fail(target->query("name")+"�Ķ���������˵�Ѿ�̫��΢�ˣ�\n");
	if( (int)me->query("neili") < 200 )
		return notify_fail("������������������ԶԿ����������С���͵���\n");
	if( (int)target->query("qi") < 50 )
		return notify_fail( target->query("name") + "�Ѿ������ˣ����޷�����������ȡ�κζ��أ�\n"); 
	if( (int)me->query("qi") < 50 )
		return notify_fail( "��첻���ˣ������������ģ�\n");

	message_vision(BLU"$NС������Ľ����쵽$n����ǰ��$n�����ҧס��$N����ָ��\n"NOR, me, target);
	message_vision(BLU"ֻ��$N����һ���������϶�ʱ����һ�ɺ���������ĺ���Ӷ�ͷ����������\n" NOR, me, target);
	tell_object(me, HIG "��ֻ����" + target->query("name") + HIG+"�Ķ������˴�ԴԴ���������˽������������鲼ȫ��\n" NOR );

	target->receive_wound("qi", 2); 
	if( tg_age < 999 )
	{
//		me->add("combat_exp",1+random(4));
//		me->add("potential",1 );
		duli=3;
	}
	if( tg_age > 999 && tg_age < 9999)
	{
//		me->add("combat_exp", 1+random(7));
//		me->add("potential", 1+random(2));
		duli=5;
	}
	if( tg_age > 9999 )
	{
//		me->add("combat_exp", 2+random(9));
//		me->add("potential", 1+random(3));
		duli=7;
	}

	/*****/
//	if( (int)me->query("potential") > (int)me->query_max_pot() )
//		me->set("potential", me->query_max_pot());

	/*****/

	skill_count = duli*(10+random((int)me->query_int()));
	me->improve_skill("qianzhu-wandushou", skill_count);
	me->set_temp("wudu_suck", 1);
	call_out("del_wudusuck", 4, me, target);

	switch( random(duli) )
	{
	case 0:
		temp = (int)me->query("combat_exp");
		target->add("combat_exp", random((int)temp/3000)+10 );
		if( (int)target->query("combat_exp") > (temp*12/10) )
			target->set("combat_exp", temp*12/10);
		else
			tell_object(me, HIG+ target->query("name") + "�ľ�����ߵ�" + chinese_number((int)target->query("combat_exp")) +"�㡣\n"NOR );
		break;
	case 1:
		target->add_temp("apply/attack",1);

		if( (int)target->query_temp("apply/attack")>300 )
			target->set_temp("apply/attack",300);
		else
			tell_object(me, HIG+ target->query("name") + "�Ĺ�������ߵ�" + chinese_number((int)target->query_temp("apply/attack")) + "�㡣\n"NOR );
		break;
	case 2:
		target->add_temp("apply/defense",1);
		if((int)target->query_temp("apply/defense")>300)
			target->set_temp("apply/defense",300);
		else
			tell_object(me,HIG+target->query("name") + "�ķ�������ߵ�" + chinese_number((int)target->query_temp("apply/defense")) +"�㡣\n"NOR );
		break;
	case 3:
		target->add_temp("apply/armor",1);
		if( (int)target->query_temp("apply/armor") > 300 )
			target->set_temp("apply/armor", 300);
		else
			tell_object(me,HIG+target->query("name") + "�Ŀ����������ߵ�" + chinese_number((int)target->query_temp("apply/armor")) +"�㡣\n"NOR);
		break;
	case 4:
		target->add("max_qi",random(5)+1);
		if( target->query("max_qi") > 20000 )
			target->set("max_qi", 20000);
		else
			tell_object(me,HIG+target->query("name") + "����������ߵ�" + chinese_number((int)target->query("max_qi")) +"�㡣\n"NOR );
		break;
	case 5:
		target->add("max_jing",random(5)+1);
		if( target->query("max_jing") > 20000)
			target->set("max_jing", 20000);
		else
			tell_object(me, HIG+ target->query("name") + "�ľ���ߵ�" + chinese_number((int)target->query("max_jing")) +"�㡣\n"NOR );
		break;
	case 6:
		temp = (int)target->query_skill("dodge",1);
		target->set_skill("dodge",temp+1);
		if((int)target->query_skill("dodge",1)>300)
			target->set_skill("dodge",300);
		else
			tell_object(me, HIG""+ target->query("name") + "�Ķ���������ߵ�" + chinese_number((int)target->query_skill("dodge",1)) +"����\n"NOR);
	}
	return 1;
}

void del_wudusuck(object me,object target)
{
	if( me->query_temp("wudu_suck") ){
		me->delete_temp("wudu_suck");
		message_vision(HIG "ֻ��$N"HIG"�Ķ���Խ��Խ�󣬡���ડ�һ�����ɿ��ڵ��ڵ��ϡ�\n" NOR, target);
		message("vision", target->query("name") +"��������Ѫ������͸��һ�㱦�⣬���Ӷ�ʱ�Ǵ�����࣡\n", environment(me), ({ me }) );
		me->receive_damage("qi", 20);
	}

	target->set("eff_jing", target->query("max_jing"));
	target->set("jing", target->query("max_jing"));
	target->set("eff_qi", target->query("max_qi"));
	target->set("qi", target->query("max_qi"));
	target->set("neili", target->query("max_neili"));
	target->set("food", target->max_food_capacity());
	target->set("water", target->max_water_capacity());

	target->set_temp("nopoison", 0);
}
int help(object me)
{
	write(WHT"\nǧ������֮��ȡ����"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ϰǧ������
		��������

	����Ҫ��
		�嶾��50��
		ǧ������50��
		����200
HELP
	);
	return 1;
}


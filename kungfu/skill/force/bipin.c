// Last Modified by winder on Feb. 28 2001
// bipin.c ������ƴ
 
#include <ansi.h>;
#include <combat.h>;
inherit F_SSERVER;
int start_bipin(object me);

int exert(object me, string arg)
{
	object target;
	int myint,taint,mydex,tadex,mydodge,tadodge;
	int myexp,taexp,myneili,taneili;
	
	seteuid(getuid());

	if(!arg) return notify_fail("�����˭��ƴ������\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n"); 

	if( !target->is_fighting() ||
		!target->is_character() ||
		!me->is_fighting() )
		return notify_fail("������ƴֻ����ս����ʹ�á�\n");

	if ( !living(target) || target->query_temp("noliving") )
		return notify_fail("���ƺ������ٺ�"+target->name()+"��ƴ������\n"); 

	if(target==me) return notify_fail("����Լ���ƴ������\n"); 

	if(!me->is_fighting(target))
		return notify_fail("�������"+target->name()+"����ս����ʱ�򣬲���ʹ��������ƴ��\n");		

	if(me->query_temp("weapon") || target->query_temp("weapon"))
		return notify_fail("��˫������ս����ʱ�����ʹ��������ƴ��\n");

	myneili = me->query("neili");
	taneili = target->query("neili");

	if(me->query_skill("force", 1) < 50 )
		return notify_fail("����ڹ���Ϊ���㣬�޷��Ͷ��ֽ���������\n");

	if(myneili < 500 )
		return notify_fail("�������̫�����޷��Ͷ��ֽ���������\n");

	if(myneili*2/3 >= taneili)
		return notify_fail("���ֵ��ڹ���ΪԶ�����㣬���ñ�ƴʲô�����أ�\n");

	if((int)me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ̫�����޷��Ͷ��ֽ���������\n");

	if(me->query_temp("neili/bipin")) 
		return notify_fail("�����ں��˱�ƴ������\n");

	if(target->query_temp("neili/bipin")) 
		return notify_fail(target->name()+"���ں��˱�ƴ������\n");  

	myint = me->query_int();
	taint = target->query_int();
	mydex = me->query_dex();
	tadex = target->query_dex();
	myexp = me->query("combat_exp",1);
	taexp = target->query("combat_exp",1); 
	mydodge = me->query("dodge");
	tadodge = target->query("dodge");
	me->set_temp("bipin/target", target->query("id"));
	target->set_temp("bipin/target", me->query("id"));

	write(HIY"�����۱������������Ƴ�һ�ƣ�һ�ɾ�����Ȼѹ��" + target->name() + "ѹ�˹�ȥ��\n"NOR);
	tell_room( environment(me), HIY+me->name()+"����������������Ƴ�һ�ƣ�һ�ɾ�����Ȼ��" + target->name() + "ѹȥ��\n"NOR, ({ me })); 

	if (((myint*5+mydex*5+mydodge+myexp*2/100000) >= (taint*5+tadex*5+tadodge+taexp*2/100000)*2/3)&&(random(5)>=2))
	{
		message_combatd(HIW"$n��Ȼ��������æ˫�ȵ������Ծ�����ɣ�����ǿ�㿪$N������һ����\n"NOR, me, target);
		me->add("neili", -200);
		if( me->query("neili") < 0) me->set("neili", 0);
		me->start_busy(3);
		target->start_busy(2);
                return 0;
	} 
	else 
	{
	message_combatd(HIY"$n�ۿ��޷���������æ����������Ӳ����$N��˫�ơ�\n"NOR, me, target);

	me->add("neili",-200);
	if( me->query("neili") < 0) me->set("neili", 0);
	target->add("neili",-200);
	if( target->query("neili") < 0) target->set("neili", 0);
	me->set_temp("neili/bipin",1);
	target->set_temp("neili/bipin",1);
	me->set_temp("bipin/target", target->query("id"));
	target->set_temp("bipin/target", me->query("id"));
	target->start_busy((: start_bipin :));
	me->start_busy((: start_bipin :));
	me->set_temp("bipin/period", 1);
	return 1;
        }
}
int start_bipin(object me)
{
	string tar;
	object target, *all;
	int myneili_lost, obneili_lost, period, neili, neili2, count, ok=1;

	if(!me) return 0;
	all = all_inventory(environment(me));
	for (count=0; count<sizeof(all); count++)
		if( all[count]->query("id") == me->query_temp("bipin/target"))
		{
			ok = 0;
			target = all[count];
		}
	if (ok == 1) return 0;

	neili = me->query("neili");
	neili2 = target->query("neili");
	myneili_lost = target->query("max_neili")/200 + target->query("force")/20 + random (3);
	obneili_lost = me->query("max_neili")/200 + me->query("force")/20 + random (3);
	period = (int)me->query_temp("bipin/period"); 

	me->add("neili", -myneili_lost);
	if( me->query("neili") < 0) me->set("neili", 0);
	me->receive_damage("jing", 3+random(target->query_skill("force")/10));	
	me->receive_damage("qi", target->query("jiali")/10);
	me->improve_skill("force", random(2));

	target->add("neili", -obneili_lost);
	if( target->query("neili") < 0) target->set("neili", 0);
	target->receive_damage("jing", 3+random(me->query_skill("force")/20));	
	target->receive_damage("qi", me->query("jiali")/10);
	target->improve_skill("force", random(2));

	if(me->is_ghost()) return 0;
	if(!target || target->is_ghost() ||
		environment(me)!=environment(target))
	{
		message_combatd(CYN"$N�����ھ�һ�գ�һ˫����㼴���£�ҡҡ�ϻϵ�վ��������\n"NOR, me);
		return 0;
	}

	if(neili < myneili_lost)
	{
		message_combatd(RED"$Nֻ��ѹ��Խ��Խ�أ��ؿڷ��񣬽���ÿ��һ�������м��ѣ�ͻȻ����һ��ҡ�Σ��ε���һ�ԡ�\n"NOR, me);
		me->unconcious();
		me->add("max_neili",-5); 
		me->set_delete("bipin/target",);
		target->set_delete("bipin/target",);
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");
		message_combatd(HIW"$Nֻ���������˥���������˿���������ɫ�Ұ���ֽ��\n"NOR,target);
		return 0;
	} 
	if( (!living(target) || target->query_temp("noliving") ) &&
		(living(me) && !me->query_temp("noliving")) )
	{
		message_combatd(RED"$Nֻ��ѹ��Խ��Խ�أ��ؿڷ��񣬽���ÿ��һ�������м��ѣ�ͻȻ����һ��ҡ�Σ��ε���һ�ԡ�\n"NOR, target);
		target->unconcious();
		target->add("max_neili",-5);
		target->unconcious();
		message_combatd(HIW"$N�������˿�����ѹסɢ�ҵ���������ɫ�Ұ���ֽ��\n"NOR,me);
		me->delete_temp("bipin/target",);
		target->delete_temp("bipin/target",);  
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");  
		return 0;
	}
	if( (!living(target) || target->query_temp("noliving") ) &&
		(!living(me) || me->query_temp("noliving")) )
	{
		me->set_delete("bipin/target");
		target->set_delete("bipin/target");
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");
		message_combatd(HIW"��ʱ$N���϶����ް��Ѫɫ�������Ѿ������;��ƿ�֮ʱ��\n"NOR, me);
		me->set_temp("last_damage_from","��"+target->name()+"ͬ���ھ�");
		me->die();
		return 0;
	}

	switch(period)
	{
		case 3: 
		case 9:
		case 15:
		case 21: 
		case 27:
		case 33:
		case 39:
		case 45:
		case 51:
		case 57:
			if((neili+neili2) >=1500)
			{
				message_combatd(HIW"��һ�ᣬ$N��$nͷ����͸��һ���Ƶİ���������Խ��ԽŨ����������һ�㡣\n"NOR, me, target);
			}
			break;
		case 63:
		case 69:
		case 75:
		case 81:
		case 87:
		case 93:
		case 99:
		case 115:
		case 145:
		case 175:
		case 205:  
			if(neili > neili2)
			{
				message_combatd(HIR"$N�߶��ھ���ͷ������Խ��ԽŨ��˫�ƻ�������$n��ȥ��\n"NOR,me, target);
			}
			else
			{
				message_combatd(HIR"$N�߶��ھ���ͷ������Խ��ԽŨ��˫�ƻ�������$n��ȥ��\n"NOR,target,me);
			}
			break;
		case 12:
		case 24:
		case 42:
		case 60:
		case 78:  
		case 96: 
		case 125:
		case 155:
		case 185:
			if(neili > neili2)
			{
				message_combatd(HIR"$Nͷ���������۲�ɢ����ɫԽ��Խ�Ͼ������ϹĶ��ھ���$n��ȥ��\n"NOR, me, target);
			}
			else
			{
				message_combatd(HIR"$Nͷ���������۲�ɢ����ɫԽ��Խ�Ͼ������ϹĶ��ھ���$n��ȥ��\n"NOR, target, me);
			}
			break; 
		case 36:
		case 54:
		case 72:
		case 90:
		case 105:
		case 135:
		case 165:
		case 195:
			if(me->query("jiali") < target->query("jiali"))
			{
				message_combatd(HIR"$Nֻ������һ�����Է�����ӿ����æ�Ӿ�������\n"NOR,me);
			}
			else
			{
				message_combatd(HIR"$Nֻ������һ�����Է�����ӿ����æ�Ӿ�������\n"NOR,target);
			}
			break;
	} 

	period++;
	me->set_temp("bipin/period", period);
//	target->set_temp("bipin/period", period);
//	me->delete_temp("neili/bipin");
//	target->delete_temp("neili/bipin");
	return 1;	
}

int help(object me)
{
	write(WHT"\n�����ڹ�֮������ƴ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		����ֱ����������������ݣ��ֻ����ܾ���

	����Ҫ��
		�����ڹ�50��
		������Ϊ500
		����500
HELP
	);
	return 1;
}


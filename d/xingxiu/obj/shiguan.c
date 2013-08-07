// Room: /d/xingxiu/shiguan.c
// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit ITEM;

int start_liandu(object me);
int halt_liandu(object me);
void create()
{
	set_name(HIM"ʯ��"NOR, ({ "shi guan", "coffin", "shi", "guan"}) );
	set_weight(30000000);
	set_max_encumbrance(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("no_carry",1);
		set("no_get_from",1);
		set("no_put",1);
		set("unit", "��");
		set("long", "����һ���������ʯ��ն��Ƴɵ�ʯ�ף����������һЩ"RED"Ѫ��"NOR"��
ɢ������һ�ɸ�����ζ������������ɽ����\n");
		set("material","stone");
		set("no_get",1);
		set_temp("poison_type", "��");
	}
	setup();
}

void init()
{
	add_action("do_liandu", "liandu");
}

void over_liandu(object ob)
{
	object corp;
	remove_call_out("over_liandu");
	ob->delete_temp("liandu");
	if(objectp(corp = present("corpse", ob)))
	{
		if(ob->query_temp("liandued"))
			message_vision("\n$N"RED"�︯�õ�ʬ������һֻй������Ƥ��һ����������ʼή�������ֻʣ��һСƬѪ���ڹ׵ף�\n"NOR, ob);
		else message_vision("\n$N"RED"�︯�õ�ʬ�塰�򡱵�һ�±��ѿ��������õ�������Ѫ����\n"NOR, ob);
		destruct(corp);
		ob->delete_temp("liandued");
	}
}

int do_liandu()
{
	int liandu_cost, neili_lost, times;
	object ob, me, corp;

	ob = this_object();
	me = this_player();

	if(!ob->query_temp("liandu")) return 0;
	if(ob->query_temp("liandu_target") != me->query("id"))
		return notify_fail("������Ƹո������ȴ��һ�����εĴ��������˻�����\n");
	if(!objectp(corp = present("corpse", ob)))
		return notify_fail("��Ҫ��ʲô������\n");
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() )
		return notify_fail("ս����������ֻ���㻹û������ɣ�\n");
	if(me->query_condition("xx_liandu"))
		return notify_fail("��ո�������ɲ��ã�Ƶ��������������Σ�յģ�\n");
	if( (int)me->query("neili") < me->query("max_neili")/2 )
		return notify_fail("�����ڵ��������㣬ǿ���������Σ�յġ�\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("�����ھ�������������ȥ���Σ�յģ�\n");
	
	if (me->query_skill_mapped("force") != "huagong-dafa" ||
	me->query_skill_mapped("strike") != "chousui-zhang")
		return notify_fail("��û��ʹ�������书���޷�������\n");										 
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("�������̫����ǿ���������Σ�յģ�\n");
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("����ʱ��Ҫ˫�ֵ���ϣ���������û��ǲ�Ҫ��������\n");

	write(BLU"�㿪ʼ�����������������󷨹�������ȫ��\n"NOR);
	tell_room(environment(me), BLU+me->name()+"��ɫ��Ȼ��Ϊ���࣬˫Ŀ��˸�����������⡣\n"NOR, ({ me }));
	
	neili_lost = (int)me->query_skill("force")/10 + me->query_skill("poison")/4;
	times = (int)me->query("neili")/(int)neili_lost;
	me->set_temp("pending/liandu", 1);
	me->set_temp("liandu_times", times);
	me->set_temp("liandu/period", 1);
	ob->set_temp("liandu", 1);
	call_out("over_liandu", me->query("neili")/10, ob);
	me->start_busy((: start_liandu :), (:halt_liandu:));
	return 1;
}

int start_liandu(object me)
{
	string force;
	int neili_lost = (int)me->query_skill("force")/10 + me->query_skill("poison")/4;
	int times = (int)me->query_temp("liandu_times");
	int period = (int)me->query_temp("liandu/period");
	
	me->add("neili", -neili_lost);
	me->receive_damage("qi", 5+random(10));
	me->improve_skill("poison", 1);
	switch(period) {
	case 1:
		write("�㽫�����������������΢΢��̧��˫��ƽ�찴�ڸ��õ�ʬ���ϡ�\n");
		tell_room(environment(me), "ֻ��"+me->name()+"�����˿�����˫��ƽ�죬����ʯ���ڸ��õ�ʬ���ϡ�\n",({ me }));
		break;
	case 3:
		write("�㼱�߻����󷨣������ڵĶ��غ͹���˳�ֱ�ֱ�������õ�ʬ���ϡ�\n");
		break;
	case 5:
		write(HIY"��ʬ�ڵĶ��ؿ�ʼ��������һ�㣬��˳�������������������\n"NOR);
		break;
	case 11:
		write(YEL"��ȫ����ɣ�����Ϣ�Ե���ѭ�����������Ѩ�������Ƕ�����������ȥ��\n"NOR);
		tell_room(environment(me), YEL+me->name()+"˫�Ƴ�צ��һ�ɹ�������ָ��͸����ֱ���ڸ�ʬ������Ѩ�ϣ���������ȡʲô��\n"NOR,({ me }));
		me->improve_skill("force", me->query_con());
		break;
	case 21:
		write(HIY"\n��˫���ζ���ָ���ס��ʬ�ķ���̫��֮������������н�������󳦣���ѭθ�ڣ����Ҹ�£�
����������֮ǰ��ѭ�����Ϲ����������ڣ����㣬��ָ����ѭ��ʣ�����ָ֮�ˣ���ָ����ֱ
����ָ����������ˣ��������н���\n"NOR);
		tell_room(environment(me), CYN+me->name()+"˫���ζ����ֿ�ס�˸�ʬ�ķ���̫��֮����\n"NOR,({ me }));
		break;
	case 31:
		write(HIY"\n��ʬ�ڵĶ���Խ��Խ�ܡ���˫צ�ι�������ע����������֮������춴�ָ��ָ֮�ˣ�ѭָ������
���Ϲ�����֮�䣬��������֮�У�ѭ���������ϼ磬�ϳ������֮���ϣ�����ȱ����Σ���֧�ߣ�
���Ͼ���գ����³��У�����Ю�ڣ������У���֮�ң���֮����Ю�ǿף�����Ϣ������������
����\n"NOR);
		tell_room(environment(me), CYN+me->name()+"��������ʬ��ֻ����ƬƬ������绬�䣬�ֹ�ȴ������һ�㵭����������\n"NOR,({ me }));
		break;
	case 41:
		write(HIY"\n���ٽ�˫�ư��ڸ�ʬ����������֮������һ��һ�����������أ���أ��ϳ���ָ֮�䣬����������
֮�䣬�ϼ������������֮�ᣬ��ȱ�裬�����У�ɢ���İ����ִ������ϳ�ȱ�裬���ֱ�ϳ���
�Ͻǣ������¼������ִӶ�������У����߶�ǰ�����ա���·����һ����\n"NOR);
		tell_room(environment(me), CYN+me->name()+"˫���续̫���㻮����ֻ����ʬ�������ֵ���ɫ��ʼ�����ۺ������ؿڣ���ɫ������\n"NOR,({ me }));
		me->improve_skill("force", me->query_dex());
		break;
	case 51:
		write(YEL"��˫��ƽ̧�������������ʼ��۸�ʬ���澭����֮������\n"NOR);
		tell_room(environment(me), HIY+me->name()+"˫��ƽ̧�����������һ��������Χ����ʯ��Ʈ���ţ�������ɭ��\n"NOR,({ me }));
		break;
	case 61:
		write(BLU"������������м�֮�£�����ë�ʣ�ѭ����Ϲ�Ԫ�����ʺ�����ѭ�棬��Ŀ���࣡\n"NOR);		
		break;
	case 71:
		write(BLU"�������ߣ����ڸ��У�ѭ���ף��������أ�\n"NOR);		
		break;
	case 81:
		write(BLU"����������춸��У�ѭ���ף��������ʺ����������\n"NOR);		
		break;
	case 91:
		write(BLU"����ά������������µĽ���Ѩ����ѭ�����֫�����е������Ѩ����\n"NOR);		
		break;
	case 121:
		write(BLU"����ά������������ϵ�����Ѩ�����е���µ���ȪѨ����\n"NOR);		
		break;
	case 141:
		write(BLU"������ߣ��������壬��������֮�����������У������ж�ɢҲ��\n"NOR);		
		break;
	case 161:
		write(BLU"������ߣ���춼�в������һ�ܣ�\n"NOR); 
		me->improve_skill("force", me->query_con());
		me->add("max_neili", 1);
		break;
	case 201:
		write(RED"��Ȼ�䣬��о����Ǿ�ʬ�������ʧ������һ�������������Ĵ߶��»���Ʈ����������\n"NOR);
		tell_room(environment(me), RED"ͻȻ���Ǿ�ʬ�������ʧ������һ������"+me->name()+"�����Ĵ߶��»���Ʈ����������\n"NOR,({ me }));
		break;
	}

	if((int)me->query("neili") < 0 || (int)me->query("jingli") < 0)
	{
		write(GRN"ͻȻ�䣬��о����Լ��������Ѿ��տ���Ҳ����֮�¾��������Ķ���˳�ƶ���ֱ�ַθ���\n"NOR);
		tell_room(environment(me), GRN"ͻȻ�䣬�㿴��"+me->name()+"ȫ������һ��������Ȼ��ʯ�������¶���ֱ�嵽"+me->name()+"��ǰ�أ�\n"NOR,({ me }));
		me->set("neili", 0);
		me->apply_condition("xx_liandu", 10 + random(50));
		over_liandu(this_object());
		me->unconcious();
		return 0;
	}

	if(period==times)
	{
		write(HIW"\n�͵أ���о���һ�������Ķ���˳�ֱ�Ϯ������Ȼ͸������ھ�ֱ�ֵ��\n"NOR);
		write(HIW"��һ˲�䣬�㷢���������Ķ������Լ�����ԭ���Ķ����໥�ںϣ�һͬ���ɽ���������\n"NOR);
		tell_room(environment(me),HIY+me->name()+"�����ջ�˫�ƣ�������ȫ�������Ҳ��֮��ɢ�ˡ�\n"NOR, ({ me }));
		if(me->query_skill("poison", 1) < 180)
			me->improve_skill("poison", times*neili_lost/2*this_object()->query_temp("liandu"));
		if(me->query_skill("huagong-dafa", 1) < 200)
			me->improve_skill("huagong-dafa", me->query_con()*3);
		me->apply_condition("xx_liandu", 200 + random(200));
		this_object()->set_temp("liandued", 1);
		over_liandu(this_object());
		return 0;
	}
	period++;
	me->set_temp("liandu/period", period);
	return 1;	
}

int halt_liandu(object me)
{
	me->start_busy(1 + random(4));
	if(!wizardp(me))
		me->apply_condition("xx_liandu", 10 + random(50));
	if(living(me))
		message_vision("\n$N���һ���������ɾ�����˫�ƴ�ʯ���ϼ����ջء�\n", me);	
	over_liandu(this_object());
	return 1;
}


// baodan.c ���ӵ�
// Last Modified by winder on Aug. 1 2002

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void init();

void create()
{
	set_name("���ӵ�", ({ "baozi dan", "dan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", CYN"����һ����ȭͷһ����ı��ӵ����ֺ����̡�\n"NOR);
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	me->add("food", 50);

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		me->add("max_jingli", -1);
		me->add("eff_jingli", -1);
		me->set("jingli", 0);
		me->apply_condition("bonze_drug", 30);
		message_vision(HIR "$N����һ�ű��ӵ���ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
		destruct(this_object());
		return 1;
	}

	if( !me->query_temp("qz/baozidan") )
	{
		me->add_temp("apply/attack", 100);
		me->set_temp("qz/baozidan", 1);
		if(random(2)) me->set("max_jingli",me->query("max_jingli",1)+2);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query("con")*10);
	}

	me->add("neili", 500);
	me->apply_condition("bonze_drug",
	me->query_condition("bonze_drug")+30);
	message_vision(HIY "$N����һ�ű��ӵ���ֻ����ȫ�������������־��������о���\n" NOR, me);
	destruct(this_object());
	return 1;
}

void remove_effect(object me)
{
	me->add_temp("apply/attack", -100);
	me->delete_temp("qz/baozidan");
	tell_object(me, "����һ��������ӵ��������ྡྷ������ʧ�ˡ�\n");
}


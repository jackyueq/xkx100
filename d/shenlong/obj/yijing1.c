// yijing.c  ���Ƶ��ھ���
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

inherit ITEM;
void setup()
{}

void create()
{
	set_name("�Ƶ��ھ�", ({ "yijing", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����װ�飬�������������д�������֡�\n");
		set("value", 300);
		set("material", "paper");
	}
}

void init()
{
	add_action("do_study","study");
	add_action("do_study", "du");
}

int do_study(string arg)
{
	object ob, me = this_player(), where = environment(me);
	int cost;

	if (where->query("pigging"))
	{
		write("�㻹��ר�Ĺ���ɣ�\n");
		return 1;
	}
	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}
	if( me->is_fighting() )
	{
		write("���޷���ս����ר�������ж���֪��\n");
		return 1;
	}
	if (!id(arg))
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if( (int)me->query_skill("literate", 1) < 20 )
	{
		write("��ʶ���ֲ��࣬���������еĽ��⡣\n");
		return 1;
	}
	if( (int)me->query_skill("medicine", 1) > 29 )
	{
		write("���¶�ҽ�����м�ʶ�������ٶ����Ƶ��ھ����ˡ�\n");
		return 1;
	}
	if ( me->query("jing") < 80 )
	{
		write("��ľ���Ƿ�ѣ�����ҽ�������Ƿ��\n");
		return 1;
	}
	if( (int)me->query("sg/exp") < 1000 && !me->query_temp("sgbook_poison"))
	{
		message_vision("$N��ʳָ�ڿ���һ��պ��Щ��Һ������������\n", me);
		me->set_temp("sgbook_poison", 1);
		call_out("poison", 5, me);
	}
	cost = 30 + 600 / (int)me->query("int");
	if( me->query_temp("lu/yi1") ) cost /= 2;
	cost += random(cost / 2);

	me->improve_skill("medicine", random(2 * me->query_int()));
	me->receive_damage("jing", cost, "�����ʴ�����");
	message_vision("$Nһ��������š��Ƶ��ھ�����һ�����˼ڤ�롣\n", me);
	return 1;
}

void poison(object me)
{
	tell_object(me, HIR"��ͻȻ�е�һ��������ԭ�������Ͼ綾�����ˣ�\n"NOR);
	me->receive_wound("qi", 50, "�綾��������");
	call_out("extra", 20, me);
}

void extra(object me)
{
	me->delete_temp("sgbook_poison");
	tell_object(me, HIR"��ͻȻ�е�һ��������ԭ�������Ͼ綾�����ˣ�\n"NOR);
	message("vision", me->name()+"���¼������ģ�˫��һ�ű㲻���ˣ��ۡ������ǡ����ж�������Ѫ����\n", environment(me), ({me}) );
	if( (int)me->query_skill("force") < 120 )
		me->receive_wound("qi", me->query("max_qi")+100,"�綾��������");
	else me->unconcious();
}


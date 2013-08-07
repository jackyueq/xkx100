// yijing.c  ��ʮ�ľ����ӡ�
// Last Modified by winder on Jul. 12 2002

inherit ITEM;
void setup()
{}

void create()
{
	set_name("ʮ�ľ�����", ({ "yijing", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����װ�飬�����и�ʽͼ�׺���ϸ˵����\n");
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
	if (me->is_busy())
	{
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
	if( (int)me->query_skill("medicine", 1) < 30 )
	{
		write("�㻹����ȥ��һ�����Ƶ��ھ����ɡ�\n");
		return 1;
	}
	if( (int)me->query_skill("medicine", 1) > 59 )
	{
		write("��������֪���徭���͸���Ѩλ�������ٶ���ʮ�ľ����ӡ���\n");
		return 1;
	}
	if ( me->query("jing") < 120 )
	{
		write("��ľ���Ƿ�ѣ�����ҽ�������Ƿ��\n");
		return 1;
	}
	cost = 40 + 800 / (int)me->query("int");
	if( me->query_temp("lu/yi2") ) cost /= 2;
	cost += random(cost / 2);

	me->improve_skill("medicine", random(2 * me->query_int()));
	me->receive_damage("jing", cost, "�����ʴ�����");
	message_vision("$Nһ��������š�ʮ�ľ����ӡ���һ�����˼ڤ�롣\n", me);

	return 1;
}


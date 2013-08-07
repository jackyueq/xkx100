// Room: /d/taohua/tide.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ˮ�ף�����ӭ�������ĳ�ˮ(tide)����ʲôҲ��������
LONG
	);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
	add_action("do_hit", "hit");
	add_action("do_hit", "ji");
}

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if (arg != "bank" && arg != "anbian" && arg != "an" &&
		arg != "shore" && arg != "shatan")
		return notify_fail("��Ҫ����������\n");

	me->move("/d/jiaxing/haibin");
	message_vision("$N��Ȼ�Ӻ�ˮ����˳������ڿ�������һת�������˰��ߡ�\n", me);
	return 1;
}

int do_hit(string arg)
{
	object me = this_player();
	object weapon;
	int hit_tide, temp;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if (arg != "tide" && arg != "chao")
	{
		write("��Ҫ����ʲô��\n");
		return 1;
	}
	if (!(weapon = me->query_temp("weapon")))
	{
		write("����ź���ȭ�������һ�����ڷ�й�����жԱ��ѣգţӣԵĲ�����\n");
		return 1;
	}
	if (weapon->query("skill_type") != "sword")
	{
		write("������" + weapon->query("name") + "���ź������һӻ���һ�󣬾����Լ������ġ�\n");
		return 1;
	}
	if (me->query("neili") < 60)
	{
		write("����������㣬�޷���������ȥ��\n");
		return 1;
	}
	if (me->query("qi") < 0)
	{
		write("���Ѿ������ˣ��޷���������ȥ��\n");
		return 1;
	}
	if (weapon->query("material") != "wood" || me->query("benefit/str"))
	{
		hit_tide = weapon->query_temp("hit_tide");
		if (hit_tide == 0)
		{
			if (weapon->query("material") == "wood")
				weapon->set_temp("max_hit_tide", 5);	
			else if (weapon->query("material") == "steel")
				weapon->set_temp("max_hit_tide", 12);	
			else
				weapon->set_temp("max_hit_tide", 8);	
		}
		write("����" + weapon->query("name") + "���������ź������ڽ������÷�������һЩ����\n");
		hit_tide++;
		if (hit_tide > weapon->query_temp("max_hit_tide")) {
			write("��Ϊ���������ͣ�"+ weapon->query("name") + "��ž����һ���۶��ˣ�\n");
			destruct(weapon);
		}
		else
			weapon->set_temp("hit_tide", hit_tide);
		me->receive_damage("qi", 45);
		me->add("neili", -40);
		if (me->query_skill("sword",1) < 80)
			me->improve_skill("sword", me->query("int") / 2);
		return 1;
	}
	else
	{
		hit_tide = me->query("sea/hit_tide");
		write("����" + weapon->query("name") + "���������ź�����");
		hit_tide++;
		temp = hit_tide % 200;
		if (temp < 10)
			write(weapon->query("name") + "��Ȼ������");
		else if (temp < 20)
			write(weapon->query("name") + "��������΢�����졣");
		else if (temp < 40)
			write(weapon->query("name") + "���������͵����졣");
		else if (temp < 60)
			write(weapon->query("name") + "������ˢˢ��������");
		else if (temp < 80)
			write(weapon->query("name") + "�����˺�����������");
		else if (temp < 90)
			write(weapon->query("name") + "���������˺���������");
		else if (temp < 110)
			write(weapon->query("name") + "��Ȼ�����˺�¡¡�ľ�����");
		else if (temp < 120)
			write(weapon->query("name") + "���������˺���������");
		else if (temp < 130)
			write(weapon->query("name") + "�����˺�����������");
		else if (temp < 150)
			write(weapon->query("name") + "������ˢˢ��������");
		else if (temp < 170)
			write(weapon->query("name") + "���������͵����졣");
		else if (temp < 190)
			write(weapon->query("name") + "��������΢�����졣");
		else
			write(weapon->query("name") + "��Ȼ������");
		write("������ڹ��Լ�����������һЩ����\n");
		if (!(hit_tide % 20))
		{
			write("��Ϊ���������ͣ�"+ weapon->query("name") + "��ž����һ���۶��ˣ�\n");
			destruct(weapon);
		}
		me->set("sea/hit_tide", hit_tide);
		if (hit_tide >= 1400)
		{
			write("�������ʱ���������������е�ľ������������������ľ��磡������������ˣ�\n");
			write("�Ժ�������޷���ͨ���뺣����������ø�����ڹ���Ϊ�ˣ�\n");
			me->add("str",1);
			me->set("benefit/str", 1);
			me->delete("sea/hit_tide");
		}
		me->receive_damage("qi", 50);
		me->add("neili", -50);
		if (me->query_skill("sword",1) < 120)
			me->improve_skill("sword", me->query("int"));
		if (me->query_skill("force",1) < 120)
			me->improve_skill("force", me->query("int"));
		return 1;
	}
	return 1;
}

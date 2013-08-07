// putao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"putao"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ��������ѡ�\n");
		set("unit", "��");
		set("food_remaining", 1);
		set("food_supplay", 5);
	}
}

void init()
{
	::init();
	if( this_player() == environment() )
		add_action("do_dream", "dream");
}

int do_dream(string arg)
{
	object me;

	if ( !arg )
	{
		return notify_fail("ʲô��\n");
	}

	me = this_player();

	if ( arg == "neili" )
	{
		write("�������к�����������������������������ߡ�\n");
		me->add("neili", 10);
		me->add("max_neili", 10);
	}

	else if ( arg == "jingli" )
	{
		write("�������к��������۷���������������ʢ�ˡ�\n");
		me->add("jingli", 10);
		me->add("max_jingli", 10);
	}

	else if ( arg == "exp" )
	{
		mapping mine;
		
		mine = me->query_entire_dbase();
		write("�������к����Ѵ�ս���ٻغϣ����������\n");
		mine["combat_exp"] += 100;
	}

	else if ( arg == "potential" )
	{
		mapping mine;
		
		mine = me->query_entire_dbase();
		write("�������к����Ѵ�ս���ٻغϣ�ǳ�����Ӳ��١�\n");
		mine["potential"] = 100;
	}

	else if (
		arg == "literate" ||
		arg == "buddhism" ||
		arg == "force" ||
		arg == "unarmed" ||
		arg == "dodge" ||
		arg == "parry" ||
		arg == "magic" ||
		arg == "stealing" ||
		arg == "banruo-zhang" ||
		arg == "bashi-shentong" ||
		arg == "cibei-dao" ||
		arg == "damo-jian" ||
		arg == "fengyun-shou" ||
		arg == "fumo-jian" ||
		arg == "jingang-quan" ||
		arg == "longzhua-gong" ||
		arg == "luohan-quan" ||
		arg == "nianhua-zhi" ||
		arg == "pudu-zhang" ||
		arg == "qianye-shou" ||
		arg == "hunyuan-yiqi" ||
		arg == "sanhua-zhang" ||
		arg == "shaolin-shenfa" ||
		arg == "weituo-gun" ||
		arg == "wuchang-zhang" ||
		arg == "xiuluo-dao" ||
		arg == "yingzhua-gong" ||
		arg == "yizhi-chan" ||
		arg == "zui-gun" ||
		arg == "sword"
		)
	{
		write("���μ����Ѹ��㽲��" + to_chinese(arg) + "�ľ��ϣ������ǳ��\n");
		me->improve_skill(arg, random(10*me->query("int")));
	}
	else
		return notify_fail("ʲô��\n");

	destruct(this_object());

	return 1;
}

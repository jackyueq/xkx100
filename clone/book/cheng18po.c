// cheng18po.c

inherit ITEM;

void create()
{
	set_name("����ʮ����", ({ "cheng18po", "book2" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����Ƶ��ֳ��伮��\n");
		set("value", 4000);
		set("material", "paper");
		set("skill", ([
			"name":	      "chengzi18po",	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100,// the maximum level you can learn
			"min_skill":	50	// the maximum level you can learn
		]) );
	}
}


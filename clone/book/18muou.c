// 18muou.c

inherit ITEM;

void create()
{
	set_name("ʮ��ľż", ({ "18 muou", "muou" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"����һ��Сľ�У����е����޻�������������ľż�������ϲ
�ò�������ʹ�����ᣬ�������ŭ����ȺͿ��ף���һ��ͬ��\n");
		set("value", 5000);
		set("material", "wood");
		set("skill", ([
			"name":	      "force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	40,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	99,	// the maximum level you can learn
			"min_skill":	60	// the maximum level you can learn
		]) );
	}
}

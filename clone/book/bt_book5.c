// bt_book5.c �׾�
// Last Modified by Winder on May. 15 2001
inherit ITEM;

void create()
{
	set_name("�׾�", ({ "yi jing", "jing", "yi" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���׾���\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name": "qimen-wuxing",  // name of the skill
			"exp_required": 500,  // minimum experience required
			"jing_cost":    15,  // jing cost every time study this
			"difficulty":   18,  // the base int to learn this skill
			"max_skill":    31   // the maximum level you can learn
		]) );
	}
}

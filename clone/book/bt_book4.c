// bt_book4.c �߾�
// Last Modified by Winder on May. 15 2001

inherit ITEM;

void create()
{
	set_name("�߾�", ({ "she jing", "jing"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ŷ����������߾���\n");
		set("value", 10000);
		set("material", "paper");
		set("skill", ([
			"name": "xidu-poison", // name of the skill
			"exp_required": 300000,  // minimum experience required
			"jing_cost":    50,  // jing cost every time study this
			"difficulty":   25,  // the base int to learn this skill
			"max_skill":    151,  // the maximum level you can learn
			"min_skill":    110  // the maximum level you can learn
		]) );
	}
}

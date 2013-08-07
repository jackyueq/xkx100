// bt_book2.c ��ҩ��
// Last Modified by Winder on May. 15 2001

inherit ITEM;

void create()
{
	set_name("��ҩ��", ({ "caoyao jing", "jing", "caoyao" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������ҩ���顣\n");
		set("value", 2500);
		set("material", "paper");
		set("skill", ([
			"name": "xidu-poison",  // name of the skill
			"exp_required": 2000,  // minimum experience required
			"jing_cost":    30,  // jing cost every time study this
			"difficulty":   22,  // the base int to learn this skill
			"max_skill":    71,  // the maximum level you can learn
			"min_skill":    30   // the maximum level you can learn
		]) );
	}
}

// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name("���¾����¾�", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����¾����¾�����ͬ�����ʮһʼ�����ʵڰ�ʮһֹ��\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name"        : "taoism",
			"exp_required":	1000,
			"jing_cost"   : 20+random(20),
			"difficulty"  : 25,
			"min_skill"   : 49,
			"max_skill"   : 99,
		]) );
	}
}

// blade_book1.c

inherit ITEM;

void create()
{
	set_name("��������", ({ "blade book", "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ͨͨ�Ľ��ܵ������飬�ּ������ʲݡ�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":         "blade",
			"exp_required": 100 ,
			"jing_cost":    20+random(20),
			"difficulty":	20,
			"min_skill":	20,
			"max_skill":	30
		]) );
	}
}

// blade_book0.c

inherit ITEM;

void create()
{
	set_name("������ָ�ϡ�", ({ "blade guide", "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ͨͨ�Ľ������ʹ�õ����顣\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":         "blade",
			"exp_required": 0 ,
			"jing_cost":    20+random(20),
			"difficulty":	20,
			"min_skill":	0,
			"max_skill":	20
		]) );
	}
}

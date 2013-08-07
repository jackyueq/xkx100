// cookery_book.c

inherit ITEM;

void create()
{
	set_name( "�������", ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǳ���Щ��������ˣ���Ƥ��д�š�������š���\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": "cookery",
			"exp_required": 10000,
			"jing_cost": 40,
			"difficulty": 20,
			"max_skill": 150,
			"min_skill": 67,
		]) );
	}
}


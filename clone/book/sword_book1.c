// sword_book1.c

inherit ITEM;

void create()
{
	set_name("˵��", ({ "sword book", "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����ׯ���е�˵��ƪ���ƺ��Ի��������������档\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": 	"sword",
			"exp_required":	100,
			"jing_cost":	20,
			"difficulty":	20,
			"max_skill":	20
		]) );
	}
}

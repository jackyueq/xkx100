// cuff_book.c

inherit ITEM;

void create()
{
	set_name("ȭ������", ({ "cuff book", "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ������ͨͨ��ȭ�����ţ�������洦�ɼ���\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": 	"cuff",
			"exp_required":	100,
			"jing_cost":	20,
			"difficulty":	20,
			"max_skill":	20
		]) );
	}
}

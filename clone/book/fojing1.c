// Last Modified by winder on May. 29 2001
// fojing1.c

inherit ITEM;

void create()
{
	set_name("Ħڭɮڮ��",({"moheseng diyu","shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��𾭡�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"buddhism",
			"exp_required":	0,
			"jing_cost":	35,
			"difficulty":	20,
			"max_skill":	100
		]) );
	}
}

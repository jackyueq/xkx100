// meng.c

inherit ITEM;
void create()
{
	set_name("�α�����", ({ "stone" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ص�ʯ�����²�ֱ��ʸˣ��϶˿��Ʊ�
�⣬�ʸ˺ͱʼ�֮���һʯ�죬���Ե���һֻ��Ȼë�ʡ�\n");
		set("value", 1);
		set("skill", ([
			"name"         : "literate",
			"exp_required" : 0,
			"sen_cost"     : 30,
			"difficulty"   : 15,
			"max_skill"    : 59
		]) );
	}
}
int is_container() { return 1; }

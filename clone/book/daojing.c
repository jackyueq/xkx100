// daojing.c

inherit ITEM;

void create()
{
	set_name("���ٵ���", ({ "wanshou book", "book" }));
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�����ٵ��ء����ڻʵ���������䣬���������µ���֮�飬���ӡ�У�һ������ǧ�İٰ�ʮһ��ί�ɿ���֮�ˣ����ǻ��ѡ�����\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name"        : "taoism",
			"exp_required":	200000,
			"jing_cost"   : 50,
			"difficulty"  : 30,
			"min_skill"   : 99,
			"max_skill"   : 149,
		]) );
	}
}

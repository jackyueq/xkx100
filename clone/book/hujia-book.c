// hujia-book.c

inherit ITEM;

void create()
{
	set_name( "���ҵ���",({ "hujia book","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�����ҵ��ס�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":         "hujia-daofa",      //name of the skill
			"exp_required": 10000 ,        //minimum combat experience required
			"jing_cost":    20+random(20),// jing cost every time study this
			"difficulty":	20,           // the base int to learn this skill
			"max_skill":	99            // the maximum level you can learn
		]) );
	}
}

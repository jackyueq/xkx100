// taiji-book.c

inherit ITEM;

void create()
{
	set_name("̫��ȭ��", ({ "taiji book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
����һ�����Ƶ��ֳ��伮�������������ֳ�¼�ġ�������ҳ��ÿҳ������ʽͼ�ס�

    o,     o,    o     o      o     o      o
    )-'   /|'    )-'   )-'   (-'    )-'    )-'
    >\     >\    >\   / >     >\   / >    / >


LONG);
		set("value", 8000);
		set("material", "paper");
		set("skill", ([
			"name":	  "taiji-quan",	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	30,// the maximum level you can learn
			"min_skill":	0	// the maximum level you can learn
		]) );
	}
}


// lyj-book.c

inherit ITEM;

string* titles = ({
	"���ǽ��ĵ�",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����������ǰ�����ܽ�������ǽ������ؼ���\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name": "liangyi-sword",     // name of the skill
			"exp_required": 100000,      // minimum combat experience required
			"jing_cost":    40,     // jing cost every time study this
			"difficulty":   30,     // the base int to learn this skill
			"max_skill":    180      // the maximum level you can learn
		]) );
	}
}

void init()
{
	if(this_player()==environment() )
	{
		add_action("do_study", "study");
	}
}

int do_study(string arg)
{
	object me=this_player();

	if (arg != "shu" && arg!="book" && arg != "xinde" )
		return notify_fail("��Ҫѧʲô��\n");
	if (!present(this_object(), this_player()))
		return 0;
	if ( (int)me->query("jing")<30 )
		return notify_fail("��̫���ˣ�����Ъ�����о��ɣ�\n");

	if ((int)me->query_skill("liangyi-sword", 1) > 100
		&& (int)me->query_skill("liangyi-sword", 1) <= 180)
	{
		me->receive_damage("jing", 40);
		me->improve_skill("liangyi-sword", (me->query("int", 1))/2+(me->query_skill("literate", 1))/5,1 );
		message_vision("$N�����о������ǽ��ĵá���˼�����ã��ƺ���������\n",me);
		return 1;
	}

	return 1;
}

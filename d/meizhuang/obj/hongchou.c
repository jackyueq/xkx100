// hongchou.c
// Last Modified by winder on Sep. 27 2001

inherit ITEM;
void setup()
{}

void init()
{
	add_action("do_tear", "tear");
}

void create()
{
	set_name("���", ({"hong chou", "chou"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ĺ�񣬵��Ѿ���ʼ��ɫ�ˡ�\n");
		set("unit", "��");
		set("material", "cloth");
		set("no_get", "������Ѿ������εĶ�ס�ˡ�\n");
		set("cloth_count",1);

	}
	setup();
}

int do_tear(string arg)
{
	object me , ob;
	me = this_player();
	if (arg == "hong chou" &&
		!present("zhanyi", me) &&
		query("cloth_count")>= 1)
	{
		add("cloth_count", -1);
		ob=new(BOOK_DIR"zhanyi");
		ob->move("/d/meizhuang/dingduan");
		message_vision("$N�Ѻ��˺���������������һ���·���\n", me);
		return 1;
	}
	else {
		message_vision("$N�Ѻ��˺����������ԭ���ͱ�˺�����ˡ�\n", me);
		return 1;
	     }
}


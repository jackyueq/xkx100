// zhongyao.c ��ҩ
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_use", "use");
}
void create()
{
	set_name("��ҩ", ({"zhongyao", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ����ҩ��\n");
		set("value", 500);
	}
	setup();
}
int do_use(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("��Ҫ��ʲôҩ��\n");
	if(!present(this_object(), me)) return notify_fail("��Ҫ��ʲôҩ��\n");

	if ((int)this_player()->query("eff_qi") ==
	    (int)this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ����ҩ��\n");
	else {
		this_player()->receive_curing("qi", 25);
		message_vision("$N����һ����ҩ������ã��е����ƺö��ˡ�\n", this_player());
		destruct(this_object());
		return 1;
	}
}

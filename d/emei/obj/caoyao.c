// caoyao.c ��ҩ
inherit ITEM;
#include <ansi.h>;
void setup()
{}
void init()
{
	add_action("do_fu", "fu");
}
void create()
{
	set_name(HIG"��ҩ"NOR, ({"caoyao", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
		set("long", "����һƬ�������˵���ͨ��ҩ��\n");
		set("value", 100);
	}
	setup();
}
int do_fu(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("��Ҫ��ʲôҩ��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣�������\n");

	if (this_player()->query("eff_qi") == this_player()->query("max_qi"))
		return notify_fail("�����ڲ���Ҫ���ҩ��\n");
	else {
		this_player()->receive_curing("qi", 5);
		message_vision("$N����һƬ��ҩ���˿��ϣ��е����ƺö��ˡ�\n", this_player());
		destruct(this_object());
		return 1;
	}
}

// lbook6.c
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"��ʷ�ǡ�"NOR, ({ "literateb6", "shu6", "book6" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("long", "һ���ܹžɵ���װ�飬��Ƥ��д������׭��'ʷ��'����������ݺܶ඼�Ѿ�ģ�����塣\n");
		set("material", "paper");
	}
}
void init()
{
	add_action("do_read","study");
	add_action("do_read","du");
}
int do_read(string arg)
{
	object me;
	me = this_player();
	if (!present(this_object(), this_player())) return 0;

	if( arg=="literateb6" || arg=="shu6" || arg=="book6")
	{
		write("�Ȿ��̫�ƾ��ˣ�����û������\n");
		return 1;
	}
}

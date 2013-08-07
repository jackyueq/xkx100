// dust.c

#include <ansi.h>
inherit ITEM;
void setup()
{}
void create()
{
	set_name(HIC"ʯ�ҷ�"NOR, ({"shihui fen", "shihui", "fen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������ӻ���Ʒ���õĵ�ʯ�ҷۣ�ֻҪ����Ʒ��(guo)��ʯ�ҾͿ����ˣ�\n");
		set("value", 30);
	}
	set("pour_type", "1");
	setup();
}

void init()
{
	if( this_player()==environment() )
		add_action("do_guo", "guo");
}
								
int do_guo(string arg)
{
	object ob, me = this_player();

	if( !arg ) return notify_fail("��Ҫ��ʯ�ҷ۰���ʲô������\n");
	if(!present(this_object(), me)) return 0;
	if( me->is_busy() ) return notify_fail("����æ���������ء�\n");

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("����û������������\n");
	if( living(ob) || !ob->id("head") )
		return notify_fail("ʯ�ҷ�ֻ����������ͷ­��\n");
	message_vision("$N�ͳ�һ��ʯ�ҷۣ���$n���ʵʵ�ذ��ϡ�\n", me, ob);
	ob -> set("shihui", 1);
	destruct(this_object());
	return 1;
}


// 9book.c

#include <ansi.h>;
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"�������澭��"NOR,({ "jiuyin zhenjing", "9jing", "jing" }));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���ǻ�������ġ������澭����ֽ����Ȼ�Ѿ����ƣ���������Ȼ���Կ������������̣�\n��֮����������������㣬�ǹ���ʤʵ������ʤ���ࡣ\n");
		set("value", 3000);
		set("no_get",1);
		set("no_put",1);
		set("no_drop",1);
		set("material", "paper");
	}
}
void init()
{
  if (!query("inited"))
  {
		set("inited",1);
		remove_call_out("destbook");
		call_out("destbook", random(1200)+50);
	}
}
void destbook()
{
	message_vision(HIY "ӭ������һ��ģ��������������ˣ�������������������ͻȻһ����ͷð���������ҵ�$N����\n"HIC"ת����׷�����������Ѿ���ʧ�����ˡ�\n"NOR, this_object());
	destruct(this_object());
}

void owner_is_killed()
{
       destruct(this_object());
}

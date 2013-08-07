// book14_6.c
inherit ITEM;
int do_tear(string arg);
#include <ansi.h>;
void init()
{
	add_action("do_tear", "tear");
}

void create()
{
	set_name(HIR"��ʮ���¾���"NOR, ({"book6"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "\nһ��������ľ��飬��Ƥ(binding)�ܾ��¡�\n");
		set("unit", "��");
		set("material", "paper");
	}
	setup();
}

int do_tear(string arg)
{
	object me;
	string dir;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if(!present(this_object(), me))
		return notify_fail("��Ҫ˺ʲô��\n");

	if(arg=="book6")
	{
		message_vision("$Nһ�°Ѿ���˺�÷��顣\n", me);
		destruct(this_object());
		return 1;
	}

	if( sscanf(arg, "book6 %s", dir)==1 )
	{
		if( dir=="binding" )
		{
			if(this_object()->query("hasgot"))
				message_vision("$N����Ƥ˺����������Ƥ�Ѿ���ȡ���ˡ�\n", me);
			else
			{
				message_vision("$N����Ƥ˺����������Ƥ����������\n", me);
				message_vision("$N�Ƚ���Ƥ�ϵĵ�ͼ����������Ȼ��������յ��ˡ�\n", me);
				me->set("huanggong\haspi6", 1);
				this_object()->set("hasgot",1);  
			}
		}
		else
		{
			message_vision("$Nһ�°Ѿ���˺�÷��顣\n", me);
			destruct(this_object());
		}
		return 1;
	}	
}

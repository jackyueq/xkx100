// book14_1.c
inherit ITEM;
int do_tear(string arg);
#include <ansi.h>;
void init()
{
	add_action("do_tear", "tear");
}

void create()
{
	set_name(HIY"四十二章经"HIR"一"NOR, ({"book1"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "\n一本镶黄旗的经书，封皮(binding)很精致。\n");
		set("unit", "本");
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
		return notify_fail("你要撕什么？\n");

	if(arg=="book1")
	{
		message_vision("$N一下把经书撕得粉碎。\n", me);
		destruct(this_object());
		return 1;
	}

	if( sscanf(arg, "book1 %s", dir)==1 )
	{
		if( dir=="binding" )
		{
			if(this_object()->query("hasgot"))
				message_vision("$N将封皮撕开，发现羊皮已经被取走了。\n", me);
			else
			{
				message_vision("$N将封皮撕开，几块羊皮掉了下来。\n", me);
				message_vision("$N先将羊皮上的地图记了下来，然后把它们烧掉了。\n", me);
				me->set("huanggong\haspi1", 1);
				this_object()->set("hasgot",1);  
			}
		}
		else
		{
			message_vision("$N一下把经书撕得粉碎。\n", me);
			destruct(this_object());
		}
		return 1;
	}	
}

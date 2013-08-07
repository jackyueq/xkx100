// Obj: /d/nanshaolin/obj/gangchu.c
// Last Modified by winder on May. 29 2001

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(HIW"����"NOR,({"gang chu","chu"}));
	set_weight(100000);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","��");
		set("value",100);
		set("material","black_steel");
		set("long", HIW"����һ�����������Ľ�ħ�ƣ�ǧ������������������ĺ��⡣\n"NOR);
	       set("unwield_msg","$Nһ����Х�������ƷŻر���\n");
	}
	init_staff(30);

}
void init()
{
	add_action("do_wield","wield");
}
int do_wield(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if(!arg) return 0;
	if (arg =="gang chu"|| arg =="chu")
	{ 
		if((int)me->query_str() < 30)
		{
			tell_object(me,"���������ƣ��κι��ڳ��أ��ò�����\n");
			return 1;
		}     
		ob->wield();
		message_vision( HIW"$N˫������һ�٣���һ�����صĸ��Ƹ߸߾���������\n"NOR, me);
		return 1; 
	}
	return 0;
}

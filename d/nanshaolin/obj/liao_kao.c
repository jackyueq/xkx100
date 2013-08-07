// Obj: /d/nanshaolin/obj/liao_kao
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
void create()
{
	set_name( "����", ({ "liao kao", "kao" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "steel");
		set("armor_prop/armor",0);
		set("shaolin",1);
	}
	set("no_get",1);
	set("no_drop",1);
	setup();
}

int query_autoload()
{
	return 1;
}

void init()
{
	if (environment() == this_player())
	{
		wear();
		add_action("do_fight","fight");
		add_action("do_fight","hit");
		add_action("do_fight","kill");
		add_action("do_fight", "steal");
		add_action("do_dazuo","dazuo");
		add_action("do_dazuo","exercise");
		add_action("do_tuna","tuna");
		add_action("do_tuna","respirate");
		add_action("do_remove","remove");
	}
}

int unequip()
{
	return notify_fail("�㲻�����Ѵ�����\n");
}

int do_fight()
{
	object ob = this_player();

	if ((objectp(ob = present("liao kao", ob)) ) )
	{
		write("�������ֽŴ����������ܸ��˶��䡣\n");
		return 1;
	}
	return 0;
}

int do_dazuo()
{
	object ob = this_player();
	if ((objectp(ob = present("liao kao", ob)) ) )
	{
		write("�������ֽŴ�����������������ȷ��������������\n");
		return 1;
	}
	return 0;
}

int do_tuna()
{
	object ob = this_player();
	if ((objectp(ob = present("liao kao", ob)) ) )
	{
		write("�������ֽŴ�����������������ȷ�����������ɡ�\n");
		return 1;
	}
	return 0;
}

int do_remove(string arg)
{
	if (!arg) return 0;

	if(arg=="all")
	{
		write("�������������ֽŲ�����������һ�����ĳ��ɡ�\n");
		return 1;
	}
	return 0;
}


// yitianjian.c ���콣
// Last Modified by winder on Sep. 7 2001

#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name("���콣", ({ "yitian jian", "sword", "jian" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50000);
//		set("no_drop", "1");
		set("material", "iron");
		set("long", "�������µ�һ�������С����첻����˭�����桱֮˵��\n");
		set("wield_msg", "ֱ�������ˮ���������һ�㣬$n����$N���У����Ϊ֮��ɫ��\n");
		set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");
	}
   	init_sword(170);
	enable_commands(); 
	setup();
}

int init()
{
	if( environment(this_object())->query("id") != "zhang wuji")
	{    
		remove_call_out("destyitianjian");
		call_out("destyitianjian", 5400+random(1800));
		return 1;
	}
	else 
	return 0;
}

void destyitianjian()
{
	object ob;
	message_vision("ͻȻ�и������˴ҴҺ�������������ʧ�ڽֿڹսǴ�����⣬���$N���ˡ�\n",this_object());
	destruct(this_object());
/*	message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+"��ʧ��������콣�����ֽ�������\n"NOR, users());*/
}



// qishayan.c ��ɳ��

inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(HIM"��ɳ��"NOR, ({"qisha yan", "yan"}) );
	set("taskobj", 1);
	set_weight(100);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","��ɳ�⣬�����������ڸ������֡����������ɳ�����ᣬ��ˮ����������֮��\n");
		set("value", 0);
		set("unit" , "��");
	}
	setup();
}

	



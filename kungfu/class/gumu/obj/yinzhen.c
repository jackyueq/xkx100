// �������롣/kungfu/class/gumu/obj/yinzhen.c
// Spacenet@FXLT 1.1.2000

#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void init()
{
	add_action("do_bawan", "bawan");
}

void create()
{
	set_name(HIC"��������"NOR, ({ "ice_sting", "zhen" })); 
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���������������֮ɫ��ı������룬�����ƿ̻��ƣ�����ü��Ǿ�ϸ�������̲�ס�����(bawan)һ����\n");
		set("value", 0);
		set("base_unit", "��");
                set("base_weight", 30);
                set("base_value", 0);
                set("meterial", "iron");
		set("wield_msg", "$NС�������ȡ��һ���������뵱������\n");
		set("unwield_msg", "$N������Ż������С�\n");
	}
	set_amount(1);
	init_throwing(25);
	setup();
}

int do_bawan()
{
	if ((int)this_player()->query_condition("ice_sting") < 10) {
		tell_object(this_player(), "�㿴�����е����������Ȥ��������Ļ���ϸϸ����һ�顣\n");
		tell_object(this_player(), HIB "��ͻȻ���������������Щ��̫��㣬��Ȼ�������������ж�����˰��棬��Σ�գ���æ�ſ�����\n�������룬ֻ�����������������ī���ֱ���ľ�н������������д󺧣��̲�ס��Ҫ�޳�������\n" NOR);
		this_player()->apply_condition("ice_sting", 30);
	}	
	destruct(this_object());
	return 1;
}

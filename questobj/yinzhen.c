// Spacenet@FXLT 1.1.2000

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
	set_name(HIC"��������"NOR, ({ "ice_sting", "zhen" })); 
	set("taskobj", 1);
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
	setup();
}

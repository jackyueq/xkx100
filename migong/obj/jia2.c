#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
	set_name(HIR"������"NOR, ({ "huolong jia", "jia" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����������������Ƴɵı��ס�\n");
		set("material", "copper");
		set("unit", "��");
        set("value",100000);
		set("wear_msg", HIR "$N����һ�������ף�����ɢ���������ĺ�⡣\n" NOR);
		set("remove_msg", HIR "$N��������ж�£�С����������ڻ��\n" NOR);
		set("armor_prop/armor", 1000);
                set("armor_prop/constitution",2);
	
	}
	setup();
}

// hulannaao.c �����İ�

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIB"�����İ�"NOR, ({"hulan naao", "cloth"}));
	set_weight(1500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�׺���ɫ�Ĳ����������˶ഩ�����·�������\n");
		set("unit", "��");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	setup();
}

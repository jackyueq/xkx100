// shabu_zhizhui.c ɴ��ֱ׺

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("ɴ��ֱ׺", ({"shabu zhizhui", "cloth"}));
	set_weight(1500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�׺�ɴ���ĶԽ��·��������������ߴ�����\n");
		set("unit", "��");
		set("value", 300);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}




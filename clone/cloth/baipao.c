// baipao.c 
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("������", ({"bailuo pao", "cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"һ����ɫ�Ĵֲ��ۣ���Ȼ�ʵĲ����ã����ü���ϸ�����������з��ˡ�\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 400);
		set("armor_prop/armor", 15);

	}
	setup();
}


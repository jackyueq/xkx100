// nichang.c ��ˮ����
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit CLOTH;

void create()
{
	 set_name(HIG"��ˮ����"NOR, ({ "bishui yingshang", "cloth" }) );
	 set_weight(1000);
	 if( clonep() )
		 set_default_object(__FILE__);
	 else {
		 set("long", "һ����������������˵ı�ɫ��ȹ��������ز�֪��ʲô�������ɡ�\n");
		 set("unit", "��");
		 set("value", 8000);
		 set("material", "cloth");
		 set("armor_prop/armor", 1);
		 set("armor_prop/personality", 5);
		 set("female_only", 1);
	 }
	 setup();
}


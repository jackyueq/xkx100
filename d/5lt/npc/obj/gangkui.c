// gangkui.c �ֿ�
 
#include <armor.h>
 
inherit HEAD;
 
void create()
{
	set_name("�ֿ�", ({ "helmet", "gangkui" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "��");
		set("long", "����һ��ո�µĸֿ������Ա���ͷ����\n");
		set("value", 10000);
		set("armor_prop/armor", 30);
	}
	setup();
}
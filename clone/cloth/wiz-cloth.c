// wiz-cloth.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit CLOTH;

string* clothname = ({
	HIB"��ʦ��"NOR,
	HIC"�޷�����"NOR,
	HIY"�ƽ�ս��"NOR,
});
string* clothid = ({
	"wizard cloth",
	"wizard cloth",
	"wizard cloth",
});
string* clothlong = ({
	"����һ����ʦ�泣���������·���\n",
	"����һ��֯Ů����֯�͵��޷����¡�\n",
	"����һ���ƽ������޵�ս�ס�\n",
});

void create()
{
	int i = random(sizeof(clothname));

	set_name(clothname[i], ({ clothid[i], "cloth" }));
	set_weight(1000);
        set("long", clothlong[i]);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        //	set("long", clothlong[i]);
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 100);
		set("armor_prop/personality", 300);
	}
	setup();
}


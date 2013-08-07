// ni-cloth.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit CLOTH;

string* clothname = ({
	HIB"�಼���"NOR,
	HIC"�Ҳ����"NOR,
	HIY"�ֲ����"NOR,
});
string* clothid = ({
	"zi yi",
	"zi yi",
	"zi yi",
});
string* clothlong = ({
	"����һ�������˴����಼��¡�\n",
	"����һ�������˴��ĻҲ���¡�\n",
	"����һ�������˴��Ĵֲ���¡�\n",
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
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}


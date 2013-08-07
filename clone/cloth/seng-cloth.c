// seng-cloth.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit CLOTH;

string* clothname = ({
	CYN"�Ҳ�����"NOR,
	HIB"�಼����"NOR,
	YEL"�ֲ�����"NOR,
	CYN"�Ҳ�ֱ��"NOR,
	HIB"�಼ֱ��"NOR,
	YEL"�ֲ�ֱ��"NOR,
});
string* clothid = ({
	"jia sha",
	"jia sha",
	"jia sha",
	"zhi duo",
	"zhi duo",
	"zhi duo",
});
string* clothlong = ({
	"����һ�������˳����ĻҲ����ġ�\n",
	"����һ�������˳������಼���ġ�\n",
	"����һ�������˳����Ĵֲ����ġ�\n",
	"����һ���������泣�����ĻҲ�ֱ�֡�\n",
	"����һ���������泣�������಼ֱ�֡�\n",
	"����һ���������泣�����Ĵֲ�ֱ�֡�\n",
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
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
	}
	setup();
}


// dao-shoe.c
// Last Modified by winder on May. 25 2001

#include <ansi.h>;
#include <armor.h>;

inherit BOOTS;

string* shoename = ({
	"�Ҳ�Ь",
	HIC"�಼Ь"NOR,
	HIY"��Ь"NOR,
	YEL"��Ь"NOR,
});
string* shoeid = ({
	"bu xie",
	"bu xie",
	"ma xie",
	"cao xie",
});
string* shoelong = ({
	"����һ˫���׵ĻҲ�Ь��\n",
	"����һ˫�������е��಼Ь��\n",
	"����һ˫���������˳�������Ь��\n",
	"����һ˫���������˵Ĳ�Ь��\n",
});

void create()
{
	int i = random(sizeof(shoename));

	set_name(shoename[i], ({ shoeid[i], "shoe" }));
	set_weight(1000);
        set("long", shoelong[i]);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
//		set("long", shoelong[i]);
        	set("value", 0);
		set("material", "boots");
		set("armor_prop/dodge", 5);
	}
	setup();
}

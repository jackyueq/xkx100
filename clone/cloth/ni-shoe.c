// ni-shoe.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit BOOTS;

string* shoename = ({
	HIC"�಼��Ь"NOR,
	HIC"�Ҳ���Ь"NOR,
});
string* shoeid = ({
	"ni xie",
	"ni xie",
});
string* shoelong = ({
	"����һ˫����Ů�᳣�����಼Ь��\n",
	"����һ˫����Ů�᳣���ĻҲ�Ь��\n",
});

void create()
{
	int i = random(sizeof(shoename));

	set_name(shoename[i], ({ shoeid[i], "shoe" }));
	set_weight(900);
        set("long", shoelong[i]);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
        //	set("long", shoelong[i]);
		set("value", 0);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}

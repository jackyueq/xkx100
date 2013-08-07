// female-shoe.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit BOOTS;

string* shoename = ({
	HIM"�廨СЬ"NOR,
	"��Ь",
});
string* shoeid = ({
	"flower shoes",
	"cloth shoes",
});
string* shoelong = ({
	"����һ˫Ů�˴��ķ��Ƶúܾ������廨Ь��\n",
	"����һ˫����ͨ�Ĵֲ�Ь��\n",
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

// man-shoe.c
// Last Modified by winder on May. 25 2001
 
#include <armor.h>;
#include <ansi.h>;

inherit BOOTS;

string* shoename = ({
	"��Ь",
	"Ƥѥ",
});
string* shoeid = ({
	"cloth shoes",
	"skin shoes",
});
string* shoelong = ({
	"����һ˫����ͨ�Ĵֲ�Ь��\n",
	"����һ˫���Ϻ�ţƤ����Ƥѥ��\n",
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
	}
	setup();
}

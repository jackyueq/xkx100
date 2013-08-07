// wiz-shoe.c
// Last Modified by winder on May. 25 2001
 
#include <armor.h>;
#include <ansi.h>;

inherit BOOTS;

string* shoename = ({
	HIB"��ʦѥ"NOR,
	HIG"������"NOR,
	HIY"����֮��"NOR,
});
string* shoeid = ({
	"wizard shoe",
	"cloth shoes",
	"skin shoes",
});
string* shoelong = ({
	"����һ˫��ʦ�泣ʹ�õ�Ƥѥ��\n",
	"����һ˫���Ϻ���Ƥ����Ƥѥ��\n",
	"����һ˫������͵ķ���֮ѥ��\n",
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
       // 	set("long", shoelong[i]);
		set("value", 0);
		set("armor_prop/armor", 100);
	}
	setup();
}

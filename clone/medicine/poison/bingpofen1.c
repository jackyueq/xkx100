// bingpofen1.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>;
inherit COMBINED_ITEM;

void create()
{
	set_name(HIB"��ȼ�ı��Ƿ�"NOR, ({ "bingpo fen", "fen", "bingpo" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ��͸�����������Ķ��ۡ��Ѿ���ȼ������Ϳ(tu)�ڱ������ˡ�\n" );
		set("unit", "Щ");
		set("base_value", 5000);
		set("base_unit", "��");
		set("base_weight", 30);
		set("drug_color", ""HIB"����ɭɭ"NOR"");
		set("pour_type", "bing_poison");
	}
	set_amount(1);
}

#include "poison1.h";

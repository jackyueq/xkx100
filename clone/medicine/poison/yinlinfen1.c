// yinlinfen1.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>;
inherit COMBINED_ITEM;

void create()
{
	set_name(WHT"��ȼ�����׷�"NOR, ({ "yinlin fen", "fen", "yinlin" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ�����������Ķ��ۡ��Ѿ���ȼ������Ϳ(tu)�ڱ������ˡ�\n" );
		set("unit", "Щ");
		set("base_value", 5000);
		set("base_unit", "��");
		set("base_weight", 30);
		set("drug_color", ""WHT"��������"NOR"");
		set("pour_type", "cold_poison");
	}
	set_amount(1);
}

#include "poison1.h";

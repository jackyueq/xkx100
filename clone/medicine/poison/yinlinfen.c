// yinlinfen.c
// Last Modified by winder on Feb. 28 2001
// Last Modified by qingyun 04.9.27

#include <ansi.h>;
//inherit COMBINED_ITEM;
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name(WHT"���׷�"NOR, ({ "yinlin fen", "fen", "yinlin" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ���Թǻҡ��ߵ���Ϊԭ���Ƴɵ����������Ķ��ۡ�
������������(make)���(huodui)��Ҳ���Ե�(pour)����ˮ�
��Ϳ(tu)�ڱ����ϡ�(Ϳ֮ǰ�����ȵ�ȼ(dian)��)\n" );
		set("unit", "��");
//		set("unit", "Щ");
//		set("base_value", 5000);
//		set("base_unit", "��");
//		set("base_weight", 30);
		set("drug2", __DIR__"yinlinfen1");
		set("pour_type", "cold_poison");
	}
//	set_amount(1);
}

#include "poison.h";

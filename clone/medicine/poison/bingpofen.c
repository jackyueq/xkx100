// bingpofen.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>;
//inherit COMBINED_ITEM;
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name(HIB"���Ƿ�"NOR, ({ "bingpo fen", "fen", "bingpo" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ���Ա�󸶾֭���ϳ��ݵ�Ϊԭ���Ƴɵ�͸�����������Ķ��ۡ�������������(make)���(huodui)��Ҳ���Ե�(pour)����ˮ���Ϳ(tu)�ڱ����ϡ���Ϳ֮ǰ�����ȵ�ȼ(dian)����\n" );
//		set("unit", "Щ");
		set("unit", "��");
//		set("base_value", 5000);
//		set("base_unit", "��");
//		set("base_weight", 30);
		set("drug2", __DIR__"bingpofen1");
		set("pour_type", "bing_poison");
	}
//	set_amount(1);
}

#include "poison.h";

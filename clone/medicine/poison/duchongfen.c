// duchongfen.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>;
//inherit COMBINED_ITEM;
inherit ITEM;
inherit F_UNIQUE;

void create()
{
	set_name("�����", ({ "duchong fen", "duchong", "fen" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������򼡢֩���Ϊԭ���ƳɵĶ��ۡ�
������������(make)���(huodui)��Ҳ���Ե�(pour)����ˮ�
��Ϳ(tu)�ڱ����ϡ�(Ϳ֮ǰ�����ȵ�ȼ(dian)��)\n" );
//		set("unit", "Щ");
		set("unit", "��");
//		set("base_value", 3000);
//		set("base_unit", "��");
//		set("base_weight", 30);
		set("drug2", __DIR__"duchongfen1");
		set("pour_type", "xx_poison");
	}
//	set_amount(1);
}
#include "poison.h";


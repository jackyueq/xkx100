// Last modified by winder 2003.9.2
// /clone/misc/baowu.c

#include <ansi.h>
inherit ITEM;
string* titles = ({
	HIW"ҹ����"NOR,
	HIG"�����"NOR,
	HIY"������"NOR,
	HIG"������"NOR,
	HIR"������Ѫʯ"NOR,
	HIC"����ʯ"NOR,
	HIY"���ʯ"NOR,
	YEL"��ɽʯ"NOR,
	HIW"���ʯ"NOR,
	BLK"����ʯ"NOR,
	HIW"�ױ�ʯ"NOR,
	HIR"�챦ʯ"NOR,
	HIG"�̱�ʯ"NOR,
	HIG"����ʯ"NOR,
	HIG"��ȸʯ"NOR,
	HIC"���ʯ"NOR,
	YEL"��"HIG"�̱�ʯ"NOR,
	HIG"�̾�"NOR,
	HIM"��ˮ��"NOR,
	HIY"����"NOR,
	HIY"����"NOR,
	HIB"����ʯ"NOR,
	HIW"��ʯ"NOR,
	HIG"����"NOR,
	HIW"ˮ��"NOR,
	GRN"���"NOR,
	HIM"���"NOR,
	GRN"è����"NOR,
	HIR"ɺ��"NOR,
	HIG"����"NOR,
	WHT"��"NOR,
	WHT"������"NOR,
	CYN"���"NOR,
	CYN"����"NOR,
	CYN"���ָ"NOR,
	HIC"����"NOR,
	WHT"������"NOR,
	CYN"������"NOR,
	WHT"��յ"NOR,
	WHT"����"NOR,
	HIG"��ĸ��"NOR,
	HIG"������"NOR,
});

void create()
{
	int i = random(sizeof(titles));
	set_name(titles[i], ({"bao wu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���ڳ����ı����֪����ʲô���á�\n");
		set("unit", "��");
                set("no_sell", 1);
		set("no_put",1);
//		set("value", 50);
		set("no_beg",1);
		set("no_steal",1);
	}
}

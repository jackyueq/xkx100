// Last Modified by winder on Nov. 17 2000
// zitie.c

#include <ansi.h>
inherit ITEM;
void setup()
{}
void create()
{
	set_name( HIB"����"NOR, ({ "zitie", "tie" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			RED
			"\n�������족\n"
			"\n"
			"ŭ����ڣ�ƾ������������Ъ��\n"
			"̧���ۣ����쳤Х��׳�����ҡ�\n"
			"��ʮ��������������ǧ��·�ƺ��¡�\n"
			"Ī���У���������ͷ���ձ��С�\n"
			"\n"
			"�����ܣ���δѩ�����Ӻ�����ʱ��\n"
			"�ݳ���̤�ƣ�����ɽȱ��\n"
			"׳־���ͺ�²�⣬Ц̸������ūѪ��\n"
			"����ͷ����ʰ��ɽ�ӣ������ڡ�\n" NOR
		);
		set("value", 0);
		set("material", "paper");
	}
}

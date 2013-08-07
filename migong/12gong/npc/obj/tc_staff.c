// nine-ring.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( HIY "�Ż�����" NOR, ({ "nine-ring staff", "staff" }) );
	set_weight(90000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY "����������������֮�Ż����ȣ����������Ÿ�ͭ�����������ޱߡ�\n" NOR);
		set("value", 50000);
		set("material", "brass");
		set("wield_msg", HIY "\n$N�ó�һ���Ż������������У�ɲ�Ǽ�����һƬ���£�����ع���ҲΪ֮�𶯡�\n\n" NOR);
		set("unwield_msg", HIY "\n$N�������еľŻ����ȣ���Χ���˲Ŵ���һ��������\n\n" NOR);
	}

	init_staff(450);
	setup();
}

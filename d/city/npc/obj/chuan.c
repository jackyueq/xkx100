// chuan.c ��魺˴�

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(HIC "��魺˴�" NOR, ({"ganlanhe chuan", "chuan"}) );
	set_weight(100);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", @LONG
��魺˴���̾��£��вտ����ˣ������ں�һҡߣ��һť���������Կɿ�
�أ�üĿ�续�������˹���У���ҩ������Σ���˿���磬��������
LONG
		);
		set("unit", "��");
		set("value", 5000);
		set("armor_prop/armor",1);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N��һ��$nϵ�����䡣\n");
		set("unequip_msg","$N���������һ��$n������������档\n");
	}
	setup();
}


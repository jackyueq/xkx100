// Ѫ����

#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(HIR"Ѫ����"NOR, ({ "xuedi zi", "xuedi" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�ںڵ�һ���������ƺ�մȾ����཭��Ӣ�۵���Ѫ������
͸��һ��Ѫ�ȵ�ζ��\n");
		set("value", 0);
		set("material", "leather");
		set("wield_msg", "$N������Ц�������֣�����һ���ںڱ�����\n");
		set("unwield_msg", "$N����һ����ߣ���м���ջ�Ѫ���ӡ�\n");
	}
	setup();
}


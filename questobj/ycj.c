// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name(HIC"�㳦��"NOR, ({"yuchang jian","jian"}) );
	set_weight(10000);
	set("taskobj", 1);
	set("unit", "��");
	set("long", "����Ǵ�˵�е��㳦��������ϸ��������ȥ�쳣������\n");
	set("value",0);
	set("material", "steel");
	set("wield_msg", HIB "�͵�һ����$n"HIB"����$N���У������ʱ���������ɱ����\n" NOR);
	set("unwield_msg", HIG "$Nһ���֣�$n"HIG"�����ʡ�������Ϣ��ȴ����ɱ����\n" NOR);
	setup();
}


// jinhua.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
	set_name(HIY"������"NOR, ({ "duoming jinhua", "flower" }) );
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("base_unit", "��");
		set("base_weight", 300);
		set("base_value", 0);
		set("material", "iron");
		set("long", "�������ǽ����ŵĶ��Ű������Ⱥ��Ҷ���\n");
		set("wield_msg", HIC"$NѸ�ٵش���������һ�Ѷ����𻨣��������У�\n"NOR);
		set("unwield_msg",HIC"$N������ʣ�µĶ������ջ����С�\n"NOR);
	}
	setup();
}

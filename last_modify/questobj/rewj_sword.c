#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIY"һ������"NOR, ({ "cigar", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N����$n����ȻһЦ�����ų�̾һ�����ӿ㶵��ȡ���������ƿ�����������Ӱ���������������\n");
                set("unwield_msg", "$Nһ����̾���������Σ�����$n������������ˮ������ˮ�������Ǹ�ƨ����\n");
        }
        init_sword(30);
        setup();
}


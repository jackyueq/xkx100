// shunvjian.c
// for С��Ů

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIC "��Ů��" NOR, ({ "shu_nvjian", "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ڱ���ͨ�ڵĽ����������ý�˿���ż����֣�\n"
                            "����Ů�����Ӻ���\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N��̾һ������$n����������ʡ�\n");
                set("unwield_msg", "$N����һ�Σ�$n��Ȼ���ʡ�\n");
        }
        setup();
}


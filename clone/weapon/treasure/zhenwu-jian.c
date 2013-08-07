// zhenwu-jian.c ���佣
// Last Modified by winder on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIC"���佣"NOR, ({ "zhenwu jian", "sword", "jian" }));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�˽�����ͭ�̰�쵣���ͭ˿Ƕ������׭�ģ������䡱��\n���Ǵ���֮�������������彣���������䵱����ɽ֮����\n");
		set("value", 10000);
		set("material", "steel");
		set("weapon_prop/personality", 8);
		set("wield_msg", "$N��ৡ���һ�����$n������������ˮ���Ȼ�羵��\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(180);
	setup();
}
mixed weapon_hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query("shen") < 0 || victim->query("shen") > 0)
                return - damage_bonus / 2;

        if (me->query("shen") == 0 || victim->query("shen") == 0)
                return 0;
        if (me->query_skill_mapped("force") != "taiji-shengong")
                return 0;

        if (me->query_skill_mapped("sword") != "taiji-jian" ||
            me->query_skill("taiji-jian", 1) < 100)
                // only increase damage
                return damage_bonus / 3;

        switch (random(4))
        {
        case 0:
                if (!victim->is_busy())
                {
                victim->start_busy(me->query_skill("sword") / 100 + 1);
                return HIC "$N" HIC "��ǰһ�������е�" NOR + HIY "���佣" NOR
                       + HIC "�û�������ԲȦ����$n" HIC "��ȥ������ϸ��֮����\n"
                       "$n" HIC "���һ������֪��εֵ���ֻ���������ˣ�\n" NOR;
                }
        case 1:
                n = me->query_skill("sowrd");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                n = victim->query("eff_jing");
                n /= 2;
                victim->receive_damage("jing", n, me);
                victim->receive_wound("jing", n / 2, me);
                return random(2) ? HIY "$N" HIY "һ�����������е����佣����һ"
                                   "�����磬��ৡ���ɨ��$n" HIY "��ȥ��\n" NOR:
                                   HIY "$N" HIY "ͻȻ�����ȵ�����аħ�������"
                                   "�����������������佣" HIY "����һ����$n"
                                   HIY "��ʱ�����ۻ����ң�\n" NOR;
        }

        // double effect
        return damage_bonus;
}
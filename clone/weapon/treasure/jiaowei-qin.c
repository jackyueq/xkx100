//jiaowei qin ��β��

#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(HIM"��β��"NOR,({"jiaowei qin","qin"}));
	set_weight(500);
	if(clonep())
		 set_default_object(__FILE__);
	else{
		set("unit","��");
		set("value",40000);
		set("material","steel");
		set("long","�ഫ����ǵ�����ļ��ӻ������ȳ��Ľ�ľ���ɵ����٣��ٵ�β���Կɼ�����ɫ��\n");
		set("wield_msg",HIY"$N��������һ��,һ�Ž�β�ٱ��ѳ�����$N����.\n"NOR);
		set("unwield_msg",HIY"$Nʮָһ��������ҷȻ��ֹ��$N����β�٣��Ž����ŵİ����\n"NOR);
//		set("unequip_msg",HIY"��ʮָһ��������ҷȻ��ֹ��������β�٣��Ž����ŵİ����.\n"NOR);
	}
	init_sword(150);
	setup();
}

//int wield()
//{
//	object ob = environment();

/*	if (ob && !wizardp(ob)) {
		tell_object(ob, name() + "����ʦ��Ʒ���㲻��ʹ�ã�����������ʦ���棬�������Ը���\n");
		call_out("let_him_die", 300, ob);
		return 0;
	}*/
//	return ::wield();
//}
/*
void let_him_die(object ob)
{
	if (ob = environment()) {
		ob->add("combat_exp", -30000);
		ob->set_temp("last_damage_from", "������ʦ��Ʒ�ж�");
		ob->die();
	}
}
*/
mixed weapon_hit_ob(object me, object victim, int damage_bonus)
{
        int n;

        if (me->query_skill_mapped("sword") != "liangyi-sword" ||
            me->query_skill("liangyi-sword", 1) < 100)
//                return damage_bonus / 2;
                return 0;

        switch (random(4))
        {
        case 0:
                if (! victim->is_busy())
                {
                	victim->start_busy(me->query_skill("sword") / 100 + 1);
                  return WHT "$N" WHT "һ���Ϻȣ�������Ȼ�������н�β�٣���β�ٶ�ʱ����һ�ɼ����"
                       "������$n" WHT "ֻ��ͷ��Ŀѣ���������ʣ�\n" NOR;
                }
        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return WHT "$N" WHT "һ����ߣ����н�β��һ����ʱ��������һ������Я�ż�"
                       "�������ֱ��$n" WHT "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
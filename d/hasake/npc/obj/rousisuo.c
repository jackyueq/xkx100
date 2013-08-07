// Jay 3/17/96

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;

void create()
{
        set_name("��˿��", ({"rousi suo", "silk", "suo"}));
        set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("rigidity", 1);
                set("unique", 1);
                set("long", "����һ��΢ϸ͸��, �����������ܲ����˿����\n");
                set("value", 10000);
                set("material", "leather");
                set("wield_msg", "$N������һ��$n�������ϡ�\n");
                set("unwield_msg", "$N�����е�$n���һ�ţ��������С�\n");
        }
        init_whip(10);
        setup();
}

void init()
{
        add_action("do_tao","tao");
}

int do_tao(object me, object target)
{
        string msg;

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ֻ����ս���е�͵Ϯ�����á�\n");

        if (me->is_busy()) 
                return notify_fail("��������æ���ء�\n");

        if (me->query_skill_prepared("strike") != "chousui-zhang" ||
            me->query_skill_mapped("strike") != "chousui-zhang" ||
            me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("������Ƚ������󷨹��ͳ����Ʒ��໥��ϣ�����ʹ����˿������\n"); 
       
        if( (int)me->query_skill("huagong-dafa",1) < 80 )
                return notify_fail("��Ļ����󷨹���������ʹ�ò�����˿����\n");
        if( (int)me->query_skill("chousui-zhang",1) < 80 )
                return notify_fail("��ĳ����ƹ���������ʹ�ò�����˿����\n");

        if(me->query("combat_exp") < (int)target->query("combat_exp")/2 )
                return notify_fail("����͵Ϯ�Լ������򲻹����ˣ���������\n");
 

        tell_object(me, HIW "\n�����ķſ���˿�����߶������������۵�һ�ڡ�\n\n" NOR);
                 

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
            random(10) > 5) 
               {
                msg = HIR"$n��Ȼ����һ�٣���Ȼ���˰�ס��һ����\n" NOR;
                tell_object(target, HIB "\n������ͻȻһ�����ŷ����Լ���֪�����䱻���ö�����ס�ˣ�\n\n" NOR);
                target->start_busy(4);
                } 
          else {
                me->start_busy(2);
                msg = HIY"��Ȼ����һ���������ռ�$N�׳���ʲô�����������$n����ض��˿�ȥ��\n" NOR;
                tell_object(me, HIB "\n��ͻȻ��������ǿ�˺ܶ࣬��⣡�Լ�����ͼ�������ˣ�\n\n" NOR);
                tell_object(target, HIB "\n��ͻȻ������һ������ɫ�Ķ�����������һ��������Ծ�˿�ȥ��\n\n" NOR);
                }

        message_vision(msg, me, target);
        me->add("neili", -50);
        me->add("shen", -(random(200)));
        return 1;
}
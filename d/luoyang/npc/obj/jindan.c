// jindan.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIY"��"NOR, ({ "jin dan", "dan" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("base_unit", "��");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "gold");
                set("long", HIW"�ƳγεĽ𵨣���֮����������һ�����࣬���Ҵ��Ի���֮����\n"NOR);
                set("wield_msg", HIC"$NѸ�ٵشӰ��������ͳ�һЩ�𵨣��������оʹ�������\n"NOR);
                set("unwield_msg",HIC"$N������ʣ�µĽ𵨾����Żذ������С�\n"NOR);
        }
        set_amount(50);
        init_throwing(25);
        setup();
}


#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(CYN "�����з�" NOR, ({ "zhenyue shangfang", "zhenyue", 
                                              "jian", "sword" }));
        set_weight(8000);
        if (clonep())
//                destruct(this_object());
						set_default_object(__FILE__);
        else {
                set("long", CYN"
�˽������������λ��ʮһ���Զ���������磬���彣����Ͷ
��������Ի�����з�������׭�飬�������ͨ�����⡣������
����֮�ϻ�����������������Ĺ�׭���ƺ�����ѧ�йء�\n" NOR);
                set("unit", "��");
                set("value", 80000);
								set("no_sell",1);
                set("material", "steel");
                set("wield_msg", CYN "$N" CYN "���������Х����ʱ��"
                                 "âһ����һ������ƿջ���������$N"
                                 CYN "�Ƽ䡣\n" NOR);
                set("unwield_msg", CYN "$N" CYN "һ����ߣ������е�"
                                   "�������뽣�ʡ�\n" NOR);
                set("skill", ([
                        "name"         : "hengshan-sword",
                        "exp_required" : 300000,
                        "jing_cost"    : 40,
                        "difficulty"   : 30,
                        "max_skill"    : 150,
                        "min_skill"    : 50
                ]));

           //     set("stable", 100);
        }
        init_sword(160);
        setup();
}

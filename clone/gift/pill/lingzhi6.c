#include <ansi.h>
inherit __DIR__"pill";

void create()
{//6. ǧ����֥��	HIY	49000		25000	150		��ǧ����֥����������ҩ�������Ƶ���ҩ��

        set_name(HIY "ǧ����֥��" NOR, ({ "qiannian lingzhiwan", "lingzhi" ,"wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIY "��ǧ����֥����������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 25000);
                set("weight", 300);
                set("pill_skill", "force");
                set("skill_mapped", 1);
                set("pill_point", 49000);
                set("force_point", 150);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

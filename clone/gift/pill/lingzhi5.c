#include <ansi.h>
inherit __DIR__"pill";

void create()
{//5.  ������֥��	HIG	39000		20000	100		�ɰ�����֥����������ҩ�������Ƶ���ҩ��

        set_name(HIG "������֥��" NOR, ({ "bainian lingzhiwan", "lingzhi" ,"wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIG "�ɰ�����֥����������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 20000);
                set("weight", 300);
                set("pill_skill", "force");
                set("skill_mapped", 1);
                set("pill_point", 39000);
                set("force_point", 100);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

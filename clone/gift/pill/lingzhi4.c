#include <ansi.h>
inherit __DIR__"pill";

void create()
{//4.  ��ɽ��֥��	CYN	29000		15000	50		�ɸ�ɽ��֥����������ҩ�������Ƶ���ҩ��

        set_name(CYN "��ɽ��֥��" NOR, ({ "gaoshan lingzhiwan", "lingzhi" ,"wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", CYN "�ɸ�ɽ��֥����������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 15000);
                set("weight", 300);
                set("pill_skill", "force");
                set("skill_mapped", 1);
                set("pill_point", 29000);
                set("force_point", 50);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

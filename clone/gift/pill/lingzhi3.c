#include <ansi.h>
inherit __DIR__"pill";

void create()
{//3.  ǧ����֥	HIY	40000		20000	10		���ڸ�ɽ�ϵ����ҩ�ģ����ú�������ڹ��ȼ���

        set_name(HIY "ǧ����֥" NOR, ({ "qiannian lingzhi", "qiannian", "lingzhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIY "���ڸ�ɽ�ϵ����ҩ�ģ����ú�������ڹ��ȼ���\n" NOR);
								set("unit", "��");
                set("value", 20000);
                set("weight", 300);
                set("pill_skill", "force");
                set("skill_mapped", 1);
                set("pill_point", 40000);
                set("force_point", 10);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

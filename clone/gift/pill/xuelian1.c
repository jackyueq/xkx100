#include <ansi.h>
inherit __DIR__"pill";

void create()
{//1. ��ɽѩ��	WHT	20000		10000	3		���ڴ�ѩɽ֮�ϵ����ҩ�ģ����ú�������Ṧ�ȼ���

        set_name(WHT "��ɽѩ��" NOR, ({ "tianshan xuelian",  "xuelian", "lian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", WHT "���ڴ�ѩɽ֮�ϵ����ҩ�ģ����ú�������Ṧ�ȼ���\n" NOR);
								set("unit", "��");
                set("value", 10000);
                set("weight", 300);
                set("pill_skill", "dodge");
                set("pill_point", 20000);
                set("force_point", 3);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

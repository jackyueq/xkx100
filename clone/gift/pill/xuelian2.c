#include <ansi.h>
inherit __DIR__"pill";

void create()
{//2. ����ѩ��	CYN	30000		15000	5		���ڴ�ѩɽ֮�ϵ����ҩ�ģ����ú�������Ṧ�ȼ���

        set_name(CYN "����ѩ��" NOR, ({ "bainian xuelian",  "xuelian", "lian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", CYN "���ڴ�ѩɽ֮�ϵ����ҩ�ģ����ú�������Ṧ�ȼ���\n" NOR);
								set("unit", "��");
                set("value", 15000);
                set("weight", 300);
                set("pill_skill", "dodge");
                set("pill_point", 30000);
                set("force_point", 5);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

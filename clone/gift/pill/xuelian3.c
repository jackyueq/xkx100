#include <ansi.h>
inherit __DIR__"pill";

void create()
{//3. ǧ��ѩ��	MAG	40000		20000	10		���ڴ�ѩɽ֮�ϵ����ҩ�ģ����ú�������Ṧ�ȼ���

        set_name(MAG "ǧ��ѩ��" NOR, ({ "qiannian xuelian",  "xuelian", "lian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", MAG "���ڴ�ѩɽ֮�ϵ����ҩ�ģ����ú�������Ṧ�ȼ���\n" NOR);
								set("unit", "��");
                set("value", 20000);
                set("weight", 300);
                set("pill_skill", "dodge");
                set("pill_point", 40000);
                set("force_point", 10);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

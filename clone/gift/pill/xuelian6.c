#include <ansi.h>
inherit __DIR__"pill";

void create()
{//6. ǧ��ѩ����	HIM	49000		25000	150		��ǧ��ѩ������������ҩ�������Ƶ���ҩ��

        set_name(HIM "ǧ��ѩ����" NOR, ({ "qiannian xueliangao", "xuelian", "gao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIM "��ǧ��ѩ������������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 25000);
                set("weight", 300);
                set("pill_skill", "dodge");
                set("pill_point", 49000);
                set("force_point", 150);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

#include <ansi.h>
inherit __DIR__"pill";

void create()
{//5. ����ѩ����	HIC	39000		20000	100		�ɰ���ѩ������������ҩ�������Ƶ���ҩ��

        set_name(HIC "����ѩ����" NOR, ({ "bainian xueliangao", "xuelian", "gao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIC "�ɰ���ѩ������������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 20000);
                set("weight", 300);
                set("pill_skill", "dodge");
                set("pill_point", 39000);
                set("force_point", 100);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

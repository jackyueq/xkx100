#include <ansi.h>
inherit __DIR__"pill";

void create()
{//4. ��ɽѩ����	HIW	29000		15000	50		����ɽѩ������������ҩ�������Ƶ���ҩ��

        set_name(HIW "��ɽѩ����" NOR, ({ "tianshan xueliangao", "xuelian", "gao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIW "����ɽѩ������������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 15000);
                set("weight", 300);
                set("pill_skill", "dodge");
                set("pill_point", 29000);
                set("force_point", 50);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIG "�������" NOR, ({ "qinglong dan", "qinglong", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "����һ�Ŵ�����͸��ҩ�裬��˵���˿�����ǿ���ԡ�\n" NOR);
                set("unit", "��");
                set("value", 50000);
                set("weight", 50);
                set("gift_type", "int");
                set("gift_name", "��������");
                set("gift_point", 65);
                set("gift_msg", HIG "һ�ɻ�����Ȼ����������"
			    "��ͷʹ���ѣ�ǡ�ڴ�ʱһ������֮����Ȼ���𣬶ٸ���̩�ޱȡ�\n"NOR);
        }
        setup();
}


#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIW "���ͨ���ɵ�" NOR, ({ "tonghui xiandan", "tonghui",
                                                  "xiandan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "��˵�˵������칬�е���Ʒ�����˳��˿���ƽ�����ԡ�\n" NOR);
                set("unit", "��");
                set("value", 100000);
                set("weight", 50);
                set("gift_type", "int");
                set("gift_name", "��������");
                set("gift_point", 85);
                set("gift_msg", HIG "һ�ɻ�����Ȼ����������"
			    "��ͷʹ���ѣ�ǡ�ڴ�ʱһ������֮����Ȼ���𣬶ٸ���̩�ޱȡ�\n"NOR);
        }
        setup();
}


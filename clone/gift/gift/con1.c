#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( WHT "׳�Ƿ�" NOR, ({ "zhuanggu fen", "zhuanggu", "fen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ���Һ�ɫ��ҩ�ۣ���˵���˿�����ǿ���ǡ�\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "con");
                set("gift_name", "�������");
                set("gift_point", 40);
                set("gift_msg", HIY "�����Ĺ�����ʱ�������������ͣ���ɰ����Ż��ˣ�"
				"����һ�����ͣ���������ƺ���Ǹ�����ˡ�\n" NOR);
        }
        setup();
}


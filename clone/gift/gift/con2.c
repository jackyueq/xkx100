#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(WHT "�������ǵ�" NOR, ({ "xuanwu dan", "xuanwu", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ�ż�Ӳ�ޱȺ�ɫ��ҩ����˵���˿�����ǿ���ǡ�\n" NOR);
                set("unit", "��");
                set("value", 50000);
                set("weight", 50);
                set("gift_type", "con");
                set("gift_name", "�������");
                set("gift_point", 65);
                set("gift_msg", HIY "�����Ĺ�����ʱ�������������ͣ���ɰ����Ż��ˣ�"
				"����һ�����ͣ���������ƺ���Ǹ�����ˡ�\n" NOR);
        }
        setup();
}


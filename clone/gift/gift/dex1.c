#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( HIC "���ٸ�" NOR, ({ "fushou gao", "fushou", "gao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "����һ���������µĸ�㣬��˵���˿�����ǿ����\n" NOR);
                set("unit", "��");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "dex");
                set("gift_name", "������");
                set("gift_point", 40);
                set("gift_msg", HIW "ͻȻ��ֻ��ȫ����ƮƮ�ģ��й����Ƽ���ĸо���\n" NOR);
        }
        setup();
}


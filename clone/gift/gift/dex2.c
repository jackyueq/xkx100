#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( HIR "��ȸ���絤" NOR, ({ "zhuque dan", "zhuque", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "����һ������Ѫɫ�����ҩ�裬��˵�Ժ����ǿ����\n" NOR);
                set("unit", "��");
                set("value", 50000);
                set("weight", 50);
                set("gift_type", "dex");
                set("gift_name", "������");
                set("gift_point", 65);
                set("gift_msg", HIW "ͻȻ��ֻ��ȫ����ƮƮ�ģ��й����Ƽ���ĸо���\n" NOR);
        }
        setup();
}


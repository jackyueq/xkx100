#include <ansi.h>
inherit __DIR__"pill";

void create()
{//5.  ������ĵ�	HIR	39000		20000	100		�ɰ����˲λ���������ҩ�������Ƶ���ҩ��

        set_name(HIR "������ĵ�" NOR, ({ "bainian shenxindan",  "renshen", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIR "�ɰ����˲λ���������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 20000);
                set("weight", 300);
                set("pill_skill", "force");
                set("pill_point", 39000);
                set("force_point", 100);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

#include <ansi.h>
inherit __DIR__"pill";

void create()
{//1.  ��ɽ�˲�	HIW	20000		10000	3		���ڸ�ɽ�ϵ����ҩ�ģ����ú�����������ڹ��ȼ���

        set_name(HIW "��ɽ�˲�" NOR, ({ "gaoshan renshen", "renshen", "shen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIW "���ڸ�ɽ�ϵ����ҩ�ģ����ú�����������ڹ��ȼ���\n" NOR);
								set("unit", "��");
                set("value", 10000);
                set("weight", 300);
                set("pill_skill", "force");
                set("pill_point", 20000);
                set("force_point", 3);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

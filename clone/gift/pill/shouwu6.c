#include <ansi.h>
inherit __DIR__"pill";

void create()
{//6. ǧ�����ڵ�	WHT	49000		25000	150		��ǧ������ڻ���������ҩ�������Ƶ���ҩ��

        set_name(WHT "ǧ�����ڵ�" NOR, ({ "qiannian shouwudan","shouwu", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", WHT "��ǧ������ڻ���������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 25000);
                set("weight", 300);
                set("pill_skill", "parry");
                set("pill_point", 49000);
                set("force_point", 150);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

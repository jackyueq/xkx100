#include <ansi.h>
inherit __DIR__"pill";

void create()
{//4. ���ڵ�	YEL	29000		15000	50		�ɺ����ڻ���������ҩ�������Ƶ���ҩ��

        set_name(YEL "���ڵ�" NOR, ({ "shouwu dan", "shouwu","dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", YEL "�ɺ����ڻ���������ҩ�������Ƶ���ҩ��\n" NOR);
								set("unit", "��");
                set("value", 15000);
                set("weight", 300);
                set("pill_skill", "parry");
                set("pill_point", 29000);
                set("force_point", 50);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

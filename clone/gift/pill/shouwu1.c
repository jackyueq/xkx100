#include <ansi.h>
inherit __DIR__"pill";

void create()
{//1. ������	HIY	20000		10000	3		���ڼ���ɭ��֮�е����ҩ�ģ����ú�������мܵȼ���

        set_name(HIY "������" NOR, ({ "heshouwu",  "shouwu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIY "���ڼ���ɭ��֮�е����ҩ�ģ����ú�������мܵȼ���\n" NOR);
								set("unit", "֧");
                set("value", 10000);
                set("weight", 300);
                set("pill_skill", "parry");
                set("pill_point", 20000);
                set("force_point", 3);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

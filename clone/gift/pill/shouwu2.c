#include <ansi.h>
inherit __DIR__"pill";

void create()
{//2. ���������	HIC	30000		15000	5		���ڼ���ɭ��֮�ϵ����ҩ�ģ����ú�������мܵȼ���

        set_name(HIC "���������" NOR, ({ "bainian heshouwu",  "heshouwu",  "shouwu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIC "���ڼ���ɭ��֮�е����ҩ�ģ����ú�������мܵȼ���\n" NOR);
								set("unit", "֧");
                set("value", 15000);
                set("weight", 300);
                set("pill_skill", "parry");
                set("pill_point", 30000);
                set("force_point", 5);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

#include <ansi.h>
inherit __DIR__"pill";

void create()
{//3. ǧ�������	HIW	40000		20000	10		���ڼ���ɭ��֮�ϵ����ҩ�ģ����ú�������мܵȼ���

        set_name(HIW "ǧ�������" NOR, ({ "qiannian heshouwu", "heshouwu",  "shouwu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
								set("long", HIW "���ڼ���ɭ��֮�е����ҩ�ģ����ú�������мܵȼ���\n" NOR);
								set("unit", "֧");
                set("value", 20000);
                set("weight", 300);
                set("pill_skill", "parry");
                set("pill_point", 40000);
                set("force_point", 10);
                set("pill_msg1", HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}

//Edited by fandog, 02/15/2000
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(HIY"��Ѯ��"NOR, ({"jinbo xunhua", "hua"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"���ɫ�Ļ��䣬�����涾�ޱȵĽ�Ѯ��������Ѯ��������
����ǡ���ħ������˼���ⶾ���Ǵ����ô����ģ�ԭ����
���˽���Ϊ����ħ������\n");
                set("value", 90);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}


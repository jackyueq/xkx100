#include <ansi.h>

inherit ITEM;

void create()
{
         switch(random(13)) {
        case 0 : set_name(GRN"����ͷ��"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 1 : set_name(HIY"����������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 2 : set_name(HIW"����������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 3 : set_name(MAG"����"NOR, ({"yu pei", "yu", "pei"})); break;
        case 4 : set_name(YEL"������������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 5 : set_name(WHT"���"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 6 : set_name(WHT"��������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 7 : set_name(YEL"��������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 8 : set_name(GRN"��������ʯ��"NOR, ({"yu pei", "yu", "pei"})); break;
        case 9 : set_name(HIY"��ʽ����"NOR, ({"yu pei", "yu", "pei"})); break;
        case 10 : set_name(CYN"��������"NOR, ({"yu pei", "yu", "pei"})); break;
        case 11 : set_name(CYN"��"NOR, ({"yu pei", "yu", "pei"})); break;
        case 12 : set_name(MAG"���"NOR, ({"yu pei", "yu", "pei"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("weight", 1000);
		set("long", "���Ƕ�����ʯ��Ʒ�е�һ��������������ɽ��������һ����\n");
		set("material", "stone");
		}
	setup();
}
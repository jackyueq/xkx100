#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("���", ({ "chai he", "staff" }) );
	set_weight(2000);
        if (clonep())
        	set_default_object(__FILE__);
	else {
   	        set("unit", "��");
        	set("material", "wood");
       		set("long", "����һ���ֳ�����֦��\n");
        }
        init_staff(5);
        setup();
}

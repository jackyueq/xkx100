
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>
inherit SWORD;

void create()
{
   set_name("����", ({"west sword", "jian", "sword"}));
   set_weight(5000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("long", "����һ�������ľ��ֽ������ڷ�����\n");
     set("value", 500);
     set("material", "steel");
     set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
     set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
   }
   init_sword(450);
   setup();
  
}

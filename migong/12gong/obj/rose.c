// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;


void create()
{
  set_name(HIR "��õ��" NOR, ({ "rose", "flower"}));
  set_weight(100);
  set("long","һ����̵ĺ�õ�壬ɢ����һ˿˿���㡣\n");
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("material", "flower");
  setup();
}
